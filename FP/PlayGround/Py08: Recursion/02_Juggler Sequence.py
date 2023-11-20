def juggler(n:int, p:int):
    if p == 0: return n
    p1 = juggler(n,p-1)
    return int(p1**0.5) if p1 %2 == 0 else int(p1**1.5)