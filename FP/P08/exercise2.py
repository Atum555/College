def gcd_rec(a,b):
    if b == 0: return a
    return gcd_rec(b,a%b)