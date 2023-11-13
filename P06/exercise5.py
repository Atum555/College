def mult(M: list, N: list) -> list:
    mLineCount = len(M)
    mColumnCount = len(M[0]) 
    nLineCount = len(N)
    nColumnCount = len(N[0])
    if mColumnCount != nLineCount: return [] # Non-compatible matrixes

    result = [[0 for _ in range(nColumnCount)] for _ in range(mLineCount)]
    for lM in range(mLineCount):
        for cN in range(nColumnCount):
            subTotal = 0
            for n in range(mColumnCount): subTotal += M[lM][n] * N[n][cN]
            result[lM][cN] = subTotal
    return result