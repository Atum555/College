def factorial(n):
    r = 1
    for x in range(n,0,-1): r *= x
    return r


def C(n,r):
    return (factorial(n))/(factorial(r)*(factorial(n-r))) // 1