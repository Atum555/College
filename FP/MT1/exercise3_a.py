def approx_pi(n:int) -> float:
    sum = 0
    for i in range(n):
        sum += ((-1)**i)/(2*i+1)
    pi = 4*sum
    return (round(pi,5))