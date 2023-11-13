def solver(a,b,c):
    sqrt = b**2 -4*a*c
    if sqrt < 0: return []
    if sqrt == 0: return [-b/(2*a)]
    sqrt **= 0.5
    return sorted([(-b + sqrt)/(2*a), (-b - sqrt)/(2*a)])