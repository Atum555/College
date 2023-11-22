def paint(n:int, boards:list) -> int:
    if n == 1: return max(boards)
    return min(map(lambda x: sum(x), list(map(lambda i: (max(boards[:i]), paint(n-1, boards[i:])), range(1,len(boards)-n+2)))))


## READABLY VERSION >>>>
def paint(n:int, boards:list) -> int:
    if n == 1: return max(boards)
    result = []
    for i in range(1,len(boards)-n+2):
        result.append( ( max(boards[:i]), paint(n-1, boards[i:]) ) )

    result = map(lambda x: sum(x), result)
    return min(result)