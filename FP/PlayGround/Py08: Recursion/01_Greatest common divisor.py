def gcd_rec(n1:int, n2:int) -> int:
    if n2 == 0: return n1
    if n1 == 0: return n2
    return gcd_rec(min(n1,n2), max(n1,n2) % min(n1,n2))