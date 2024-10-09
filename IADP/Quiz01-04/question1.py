a = int(input("Coefficient of x2:"))
b = int(input("Coefficient of x:"))
c = int(input("Independent coefficient:"))

determinante = b**2 - 4*a*c
if determinante > 0:
    r1 = (-b + determinante**0.5) / (2 * a)
    r2 = (-b - determinante**0.5) / (2 * a)
    print(f"Two real roots: x1 = {r1:.2f}, x2 = {r2:.2f}")

if determinante == 0:
    r = -b / (2 * a)
    print(f"Double root x = {r:.2f}")

if determinante < 0:
    print("There are no real roots")
