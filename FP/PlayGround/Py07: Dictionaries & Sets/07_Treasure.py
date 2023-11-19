def treasure(clues:dict):
    location = (0,0)
    while location in clues:
        key = location
        location = clues[location]
        del clues[key]
    return location