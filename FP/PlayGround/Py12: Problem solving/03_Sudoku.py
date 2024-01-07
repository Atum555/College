def solve_sudoku(board:list):
    s = {1,2,3,4,5,6,7,8,9}
    flag = True
    while flag:
        flag = False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] != 0: continue
                flag = True
                
                # Line
                if len(r:= s - set(board[i])) == 1:
                    board[i][j] = r.pop()
                    continue
                
                # Col
                if len(r:= s - set([board[i][x] for x in range(len(board[0]))])) == 1:
                    board[i][j] = r.pop()
                    continue

                # Cube
                p = (i//3, j//3)
                if len(r:= s - set([board[p[0]*3+x][p[1]*3+y] for x in range(3) for y in range(3)])) == 1:
                    board[i][j] = r.pop()
                    continue
    return board