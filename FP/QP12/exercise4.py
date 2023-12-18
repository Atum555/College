def move_ball(b):
    board = list(map(lambda x: [y for y in x], b))
    direction = ""
    possitions = []
    possition = ()
    for y in range(len(board)):
        for x in range(len(board[0])):
            if board[y][x] in "NSWE":
                direction = board[y][x]
                possitions.append((y,x))
                possition = (y,x)
    while True:
        if direction == "N":
            possition = (possition[0]-1, possition[1])
        elif direction == "S":
            possition = (possition[0]+1, possition[1])
        elif direction == "E":
            possition = (possition[0], possition[1]+1)
        elif direction == "W":
            possition = (possition[0], possition[1]-1)
        
        possitions.append(possition)
        if board[possition[0]][possition[1]] == "X":
            break
        elif board[possition[0]][possition[1]] == "/":
            if direction == "S": direction = "W"
            elif direction == "W": direction = "S"
            elif direction == "N": direction = "E"
            elif direction == "E": direction = "N"
        elif board[possition[0]][possition[1]] == "\\":
            if direction == "S": direction = "E"
            elif direction == "E": direction = "S"
            elif direction == "N": direction = "W"
            elif direction == "W": direction = "N"

    return possitions