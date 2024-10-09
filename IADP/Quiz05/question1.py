n = int(input("n:"))
r = 1
while n > 1:
    r *= n
    n -= 1

print(f"Factorial = {r}")
