import math
def approx_cos(x:int, n:int):
    r = 0
    for k in range(n):
        r += (((-1)**k)/(math.factorial(2*k)))*(x**(2*k))
    return round(r,5)