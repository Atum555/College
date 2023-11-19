def magic(mat:list) -> bool:
    if len(mat) < 3: return False               # Restrição a matrizes 3x3 ou maiores
    for x in mat: 
        if len(x) != len(mat): return False     # Restrição a matrizes não quadradas ou incorretas
    total = sum(mat[0])                         # Soma

    """
    [[00,01,02],    list[linha][coluna]
    [10,11,12],
    [20,21,22]]
    """
    
    # Linhas
    for line in mat:
        if total != sum(line): return False
        
    # Colunas
    for column in range(len(mat)):
        subTotal = 0
        for line in mat: subTotal += line[column]
        if total != subTotal: return False
        
    # Diagonais
    subTotal1 = 0
    subTotal2 = 0
    for i in range(len(mat)):
        subTotal1 += mat[i][i]      # Diagonal Pricipal
        subTotal2 += mat[i][-(i+1)] # Diagonal Secundaria
    if subTotal1 != total or subTotal2 != total: return False
    return True