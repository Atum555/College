n = int(input("n:"))
f = 1
for i in range(n, 1, -1):
    f *= i
print(f"Factorial = {f}")
