from math import factorial
def pascal(n):
    r = ""
    for i in range(n):
        r += "\n"
        for j in range(i+1):
            r += str(int((factorial(i))/(factorial(j)*factorial(i-j)))) + " "
        r = r[:-1]
    return r