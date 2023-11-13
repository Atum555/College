"""
Code By: Cláudio Meireles

Code on GitHub: https://github.com/Atum555/Conway-s-Game-of-Life-Python

Modules required: pygame
Minimum version tested: 3.10.12
(Type hints used)

---INTERACTIONS---
MoveUp        Numpad8 ArrowUp KeyW
MoveDown      Numpad2 ArrowDown KeyS
MoveRight     Numpad6 ArrowRight KeyD
MoveLeft      Numpad4 ArrowLeft KeyA
Zoom+         NumpadAdd KeyZ
Zoom-         NumpadSubtract KeyX
Speed+        NumpadMultiply KeyC
Speed-        NumpadDivide KeyV
MoveToCenter  Numpad0 KeyO
ZoomReset     NumpadDecimal KeyL
SpeedReset    Numpad1 KeyF
Pause/Play    KeyP
Run1Iteration KeyI
RandomSpawn   KeyR
ClearWorld    KeyQ
"""


import pygame, math, random, time
from typing import TypeAlias

Position: TypeAlias = tuple[int,int]
World:    TypeAlias = dict[Position,bool]
Camera:   TypeAlias = dict[str, float]

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    LIGHTGREY = '\033[37m'
    DARKGREY = '\033[90m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def tick(world:World) -> World:
    """
    This function takes a dictionary representing the current state of the world, 
    where the keys are tuples representing the coordinates of each cell and the values 
    are booleans representing whether the cell is alive or dead. It returns a new 
    dictionary representing the next state of the world, where the keys are the same as 
    in the input dictionary and the values are booleans representing whether the 
    corresponding cell is alive or dead in the next state.
    Dead cells are not represented, meaning the boolean values are mere place holders.
    However they must be set to TRUE.

    Args:
    - world: a dictionary representing the current state of the world

    Returns:
    - a dictionary representing the next state of the world
    """
    count :dict[Position,int] = {}  # Dict to store neighbor cells
    for position in world:
        x = position[0] 
        y = position[1]
        for x in [
            (x-1, y+1),
            (x,   y+1),
            (x+1, y+1),

            (x-1, y),
            (x+1, y),

            (x-1, y-1),
            (x,   y-1),
            (x+1, y-1),
        ]:
            if not count.get(x): count[x] = 1
            else: count[x] += 1

    newWorld :World = {}  # Dict to store newWorld state after tick
    for position in count:
        if ((world.get(position) and count[position] == 2) or  # Is alive and 2 neighbors
            (count[position] == 3)):                           # Three neighbors
            newWorld[position] = True
    return newWorld

def randomCells(window:pygame.surface.Surface, world:World, camera:Camera) -> World:  
    z = camera["zoom"]
    xInit = window.get_width() /2 - camera["x"]*z  
    yInit = window.get_height()/2 + camera["y"]*z  

    xMin = math.ceil(-xInit / (CELL_SIZE *z) + (window.get_width()  / (CELL_SIZE *z))*0.1)
    yMin = math.ceil(-yInit / (CELL_SIZE *z) + (window.get_height() / (CELL_SIZE *z))*0.1) 
    xMax = math.ceil(xMin + (window.get_width()  / (CELL_SIZE *z))*0.8)
    yMax = math.ceil(yMin + (window.get_height() / (CELL_SIZE *z))*0.8)

    for x in range(xMin, xMax):
        for y in range(yMin, yMax):
            if random.choice((True, False)): world[(x,y)] = True 
    return world

def render(window:pygame.surface.Surface, world:World, camera:Camera):
    window.fill("#001629")  # Paint Window BackGround

    z = camera["zoom"]
    radius = CELL_SIZE*z*0.45
    wWidth = window.get_width()
    wHeight = window.get_height()
    xInit = wWidth /2 - camera["x"]*z  # Get center of Screen
    yInit = wHeight/2 + camera["y"]*z  # Get center of Screen

    for cell in world:
        x = xInit + cell[0] * CELL_SIZE *z
        y = yInit + cell[1] * CELL_SIZE *z
        if -radius <= x <= wWidth + radius and -radius <= y <= wHeight + radius:  # Ignore out-of-sight cells 
            pygame.draw.circle(
                window, 
                "#fdfdfd", 
                (x, y),
                radius
            )

    pygame.display.flip()  # Update Screen

def main():
    window = pygame.display.set_mode((WINDOW_WIDTH,WINDOW_HEIGHT))
    pygame.display.set_caption("Conway's Game of Life")
    clock = pygame.time.Clock()

    world:World = {}    # Init World
    camera:Camera = {   # Init Camera
        "x": 0,
        "y": 0,
        "zoom": 1,
        "speed": 5
    }
    world = randomCells(window, world, camera)  # Init random Cells


    run = True
    while True:
        # Handle Events
        for event in pygame.event.get():
            if event.type == pygame.QUIT: pygame.quit(); exit(0)  # Close Button
            if event.type == pygame.MOUSEBUTTONDOWN:  # Mouse Click
                xCor, yCor = event.pos
                xInit = window.get_width() /2 - camera["x"]*camera["zoom"] + CELL_SIZE *camera["zoom"]/2
                yInit = window.get_height()/2 + camera["y"]*camera["zoom"] + CELL_SIZE *camera["zoom"]/2
                x = math.ceil((xCor - xInit) / (CELL_SIZE *camera["zoom"]))
                y = math.ceil((yCor - yInit) / (CELL_SIZE *camera["zoom"]))
                if event.button == 1: world[(x,y)] = True
                if event.button == 3: del world[(x,y)]
                del xCor, yCor, xInit, yInit, x, y                    
            if event.type == pygame.KEYDOWN:  # Key Presses
                match event.key:
                    case pygame.K_w | pygame.K_UP    | pygame.K_KP8: camera["y"] += 50/camera["zoom"]  # Move Up
                    case pygame.K_s | pygame.K_DOWN  | pygame.K_KP2: camera["y"] -= 50/camera["zoom"]  # Move Down
                    case pygame.K_d | pygame.K_RIGHT | pygame.K_KP6: camera["x"] += 50/camera["zoom"]  # Move Right
                    case pygame.K_a | pygame.K_LEFT  | pygame.K_KP4: camera["x"] -= 50/camera["zoom"]  # Move Left

                    case pygame.K_z | pygame.K_KP_PLUS:  camera["zoom"] *= 1.2  # Zoom In
                    case pygame.K_x | pygame.K_KP_MINUS: camera["zoom"] *= 0.8  # Zoom Out

                    case pygame.K_c | pygame.K_KP_MULTIPLY:  camera["speed"] *= 0.8  # Speed +
                    case pygame.K_v | pygame.K_KP_DIVIDE:    camera["speed"] *= 1.5  # Speed -
                    
                    case pygame.K_l | pygame.K_KP_PERIOD: camera['zoom'] = 1             # Zoom Reset
                    case pygame.K_o | pygame.K_KP0:       camera['x'] = camera["y"] = 0  # Move to Center
                    case pygame.K_f | pygame.K_KP1:       camera["speed"] = 5            # Speed Reset

                    case pygame.K_p: run = not run                               # Play/Pause
                    case pygame.K_i: world = tick(world)                         # Run one Iteration
                    case pygame.K_r: world = randomCells(window, world, camera)  # Spawn Random
                    case pygame.K_q: world = {}                                  # Clear World
                
                # Speed Check
                if camera["speed"] > 30:  camera["speed"] = 30
                if camera["speed"] < 0.3: camera["speed"] = 0.3
                if camera["zoom"] < 0.14:  camera["zoom"] = 0.14
                #print(camera)

        # Tick World
        tickTime = time.time_ns()
        if run: world = tick(world)
        tickTime = time.time_ns() - tickTime

        # Render and fps limit
        renderTime = time.time_ns()
        render(window, world, camera)
        renderTime = time.time_ns() - renderTime
        clock.tick(60/camera["speed"])

        # Print Statics
        totalTime = (tickTime+renderTime)/1_000_000
        colour = bcolors.OKGREEN if totalTime < 1/60*1000 else bcolors.WARNING if totalTime < 1/30*1000 else bcolors.FAIL
        print(f"Tick: {tickTime/1_000_000:.3f} ms\t\tRender: {renderTime/1_000_000:.3f} ms\t\tTotal: {colour}{totalTime:.3f}{bcolors.ENDC} ms")

if __name__=="__main__":
    WINDOW_HEIGHT = 450
    WINDOW_WIDTH = 800
    CELL_SIZE = 20
    main()