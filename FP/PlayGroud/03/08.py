def factorial(n):
    r = 1
    for x in range(n,0,-1): r *= x
    return r

sum = 0
for k in range(51):
    sum += (factorial(4*k)*(1103+26390*k))/(((factorial(k))**4)*(396**(4*k)))
r = 1/(((2*(2**0.5))/9801)*sum)
print(round(r,8))