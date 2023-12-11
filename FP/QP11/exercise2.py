def find_me(f, limits:tuple) -> int:
    n = sum(limits) // 2
    c = 1
    while f(n): 
        limits = (n+1, limits[1]) if f(n) == 1 else (limits[0], n-1)
        n = sum(limits) // 2
        c += 1
    return c