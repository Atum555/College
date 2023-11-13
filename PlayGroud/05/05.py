def map(pos:tuple, steps:str) -> tuple:
    pos = list(pos)
    up = list(filter(lambda x: x == "up", steps.split("-")))
    down = list(filter(lambda x: x == "down", steps.split("-")))
    left = list(filter(lambda x: x == "left", steps.split("-")))
    right = list(filter(lambda x: x == "right", steps.split("-")))
    def upF(_): pos[1] += 1
    def downF(_): pos[1] -= 1
    def leftF(_): pos[0] -= 1
    def rightF(_): pos[0] += 1
    list(filter(upF, up))
    list(filter(downF, down))
    list(filter(leftF, left))
    list(filter(rightF, right))
    return tuple(pos)