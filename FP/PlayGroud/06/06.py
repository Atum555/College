def min_path(path:list[str]) -> list[str]:

    def mapValue(move:str) -> int:
        if move == "UP": return 1
        elif move == "DOWN": return -1
        elif move == "RIGHT": return 2
        elif move == "LEFT": return -2
        exit(-1)

    i = 0
    while True:
        if i+1 == len(path): break
        if not mapValue(path[i]) + mapValue(path[i+1]): 
            path.pop(i+1); path.pop(i)
            i = 0; continue
        i += 1
    return path

print(min_path(['UP', 'DOWN', 'UP', 'LEFT', 'RIGHT']))