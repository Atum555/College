def find_treasure(pos:tuple, steps:list) -> tuple:
    if len(steps) == 0: return pos
    return find_treasure(
        (pos[0] + int(steps[0] == "right") + -int(steps[0] == "left"), 
         pos[1] + int(steps[0] == "up")    + -int(steps[0] == "down")),
        steps[1:])