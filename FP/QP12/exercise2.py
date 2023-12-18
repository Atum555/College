# One-Liner
def tic_tac_toe(b:str, player:str): return [(chr(ord("A")+i) + str(j+1)) for i in range(len(b.split("\n"))) for j in range(len(b.split("\n"))) if list(map(lambda x: [y for y in x], b.split("\n")))[i][j] == " " and any([all([list(map(lambda k: (k[1] if i != k[0] else list(map(lambda l: (l[1] if l[0] != j else player), enumerate(k[1])))), enumerate(list(map(lambda x: [y for y in x], b.split("\n"))))))[g][g] == player for g in range(len(b.split("\n")))]), all([list(map(lambda k: (k[1] if i != k[0] else list(map(lambda l: (l[1] if l[0] != j else player), enumerate(k[1])))), enumerate(list(map(lambda x: [y for y in x], b.split("\n"))))))[i][len(range(len(b.split("\n"))))-1-u] == player for u in range(len(b.split("\n")))]), any([any([all([list(map(lambda k: (k[1] if i != k[0] else list(map(lambda l: (l[1] if l[0] != j else player), enumerate(k[1])))), enumerate(list(map(lambda x: [y for y in x], b.split("\n"))))))[r][h] == player for h in range(len(b.split("\n")))]), all([list(map(lambda k: (k[1] if i != k[0] else list(map(lambda l: (l[1] if l[0] != j else player), enumerate(k[1])))), enumerate(list(map(lambda x: [y for y in x], b.split("\n"))))))[h][r] == player for h in range(len(b.split("\n")))])]) for r in range(len(b.split("\n")))])])][0]


# Normal
def tic_tac_toe(b:str, player:str):
    
    def doesXWin(board:list, p:str):
        for i in range(len(board)):
            if all([board[i][j] == p for j in range(len(board))]): return True
            if all([board[j][i] == p for j in range(len(board))]): return True
        if all([board[i][i] == p for i in range(len(board))]): return True
        if all([board[i][len(board)-1-i] == p for i in range(len(board))]): return True
        return False
    
    board = list(map(lambda x: [y for y in x], b.split("\n")))
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == " ":
                b2 = board.copy()
                b2[i][j] = player
                if doesXWin(b2, player): return chr(ord("A")+i) + str(j+1)