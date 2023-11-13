def move_tower(height, from_pole, to_pole, with_pole, stepN = 1):
    """A recursive function to move a tower of given height >= 1"""
    if height > 1:
        stepN = move_tower(height-1, from_pole, with_pole, to_pole, stepN)
        print(f"{stepN}. Move disk from", from_pole, "to", to_pole)
        stepN += 1
        stepN = move_tower(height-1, with_pole, to_pole, from_pole, stepN)
        return stepN
    
    print(f"{stepN}. Move disk from", from_pole, "to", to_pole)
    stepN += 1
    return stepN