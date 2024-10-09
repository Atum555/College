x = float(input("x:"))
y = float(input("y:"))

r = (3 * y + (2*x*(y + 10))**0.5) / (4 * x + y)

print(f"f({x:.2f},{y:.2f}) = {r:.2f}")
