def bisect(f, n:int):
    lower, upper = 0, 1
    mid = 0
    for _ in range(n):
        fmid, fl = f(mid:= ((lower + upper) / 2)), f(lower)
        if fl * fmid > 0: lower = mid
        else: upper = mid
    return round(mid, 5)