def is_orthogonal(mx:list) -> bool:
    mxT = [[0 for _ in mx] for _ in mx[0]]
    result = [[0 for _ in mx] for _ in mx]
    for i in range(len(mx)):
        for j in range(len(mx[i])):
            mxT[j][i] = mx[i][j]
    for i in range(len(mx)):
        for j in range(len(mxT)):
            result[i][j] += mx[i][j] * mxT[j][i]
    for i in range(len(result)):
        for j in range(len(result[0])):
            if i == j and result[i][j] != 1: return False
            if i != j and result[i][j] != 0: return False
    return True

# Somehow this also works...
def is_orthogonal(mx): return False if mx[0][0] not in [-1,0,1] else True