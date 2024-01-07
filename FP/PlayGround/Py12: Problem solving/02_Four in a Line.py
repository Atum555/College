def four_in_line(board:list):    
    # Lines
    for i, line in enumerate(board):
        last4 = (0,0,0,0)
        for j, piece in enumerate(line):
            last4 = *last4[1:], piece
            if all(map(lambda x: x==1, last4)) or all(map(lambda x: x==2, last4)):
                return {(i, j-3), (i, j)}
            
    # Cols
    for i in range(len(board[0])):
        last4 = (0,0,0,0)
        for j in range(len(board)):
            last4 = *last4[1:], board[j][i]
            if all(map(lambda x: x==1, last4)) or all(map(lambda x: x==2, last4)):
                return {(j-3, i), (j, i)}
            
    # Diagonals
    for i in range(len(board)-3):
        for j in range(len(board[0])):
            if j+3 <= len(board[0])-1:
                if board[i][j] == board[i+1][j+1] == board[i+2][j+2] == board[i+3][j+3]:
                    return {(i, j), (i+3, j+3)}
            if j-3 >= 0:
                if board[i][j] == board[i+1][j-1] == board[i+2][j-2] == board[i+3][j-3]:
                    return {(i, j), (i+3, j-3)}