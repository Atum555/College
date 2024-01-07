def intro():
    print("After a drunken night out with friends, you awaken in a thick, dank forest. A slobbering orc is running towards you.")
    print("A. Grab a nearby rock and throw it at the orc")
    print("B. Lie down and wait to be mauled")
    print("C. Run")
    m = {
        "a": option_rock,
        "A": option_rock,
        "b": intro_gameOver,
        "B": intro_gameOver,
        "c": option_run,
        "C": option_run
    }
    (m[input()])()

def intro_gameOver():
    print("Welp, that was quick. You died!")



def option_rock():
    print("The orc is stunned, but regains control. He begins running towards you again.")
    print("A. Run")
    print("B. Throw another rock")
    print("C. Run towards a nearby cave")
    m = {
        "a": option_run,
        "A": option_run,
        "b": rock_gameOver,
        "B": rock_gameOver,
        "c": option_cave,
        "C": option_cave
    }
    (m[input()])()

def rock_gameOver():
    print("The rock flew well over the orcs head. You missed. You died!")



def option_run():
    print("You run as quickly as possible.")
    print("A. Hide behind boulder")
    print("B. Trapped, so you fight")
    print("C. Run towards an abandoned town")
    m = {
        "a": run_gameOver1,
        "A": run_gameOver1,
        "b": run_gameOver2,
        "B": run_gameOver2,
        "c": option_town,
        "C": option_town
    }
    (m[input()])()

def run_gameOver1():
    print("You're easily spotted. You died!")

def run_gameOver2():
    print("You're no match for an orc. You died!")



def option_cave():
    print("Before you fully enter, you notice a shiny sword on the ground. Do you pick up a sword. Y/N?")
    sword = input()
    print("What do you do next?")
    print("A. Hide in silence")
    print("B. Fight")
    print("C. Run")
    a = {
        "y": cave_gameOver1,
        "Y": cave_gameOver1,
        "n": cave_gameOver1,
        "N": cave_gameOver1
    }
    b = {
        "y": cave_Victory,
        "Y": cave_Victory,
        "n": cave_gameOver2,
        "N": cave_gameOver2
    }
    c = {
        "y": cave_run,
        "Y": cave_run,
        "n": cave_run,
        "N": cave_run
    }
    m = {
        "a": a,
        "A": a,
        "b": b,
        "B": b,
        "c": c,
        "C": c
    }
    ((m[input()])[sword])()

def cave_run():
    print("The orc turns around and sees you running.")
    option_run()

def cave_gameOver1():
    print("I think orcs can see very well in the dark, right? You died!")

def cave_gameOver2():
    print("You're defenseless. You died!")

def cave_Victory():
    print("As the orc reached out to grab the sword, you pierced the blade into its chest. You survived!")



def option_town():
    print("You notice a purple flower near your foot. Do you pick it up? Y/N")
    m = {
        "y": town_Victory,
        "Y": town_Victory,
        "n": town_gameOver,
        "N": town_gameOver
    }
    (m[input()])()

def town_Victory():
    print("You quickly hold out the purple flower. The orc was looking for love. This got weird, but you survived!")
    
def town_gameOver():
    print("Maybe you should have picked up the flower. You died!")

intro()