from functools import reduce as red
def power2(A:list) -> list: return [[red(lambda x,y: x|y, map(lambda k: A[i][k] & A[k][j], range(len(A)))) for j in range(len(A))] for i in range(len(A))]