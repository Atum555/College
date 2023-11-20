def no_consecutives1(k:int, previous:bool = False):
    if k == 2: return 2 if previous else 3
    return no_consecutives1(k-1) if previous else no_consecutives1(k-1) + no_consecutives1(k-1, previous= True)