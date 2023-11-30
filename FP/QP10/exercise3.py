# One-liner
def pythagoreans(a:int, b:int): return list((x,z,z) for x in range(a,b) for y in range(a,b) for z in range(a,b) if x**2 + y**2 == z**2 and x < y < z)

# Normal
def pythagoreans(a:int, b:int):
    r = range(a,b)
    values = ((x,z,z) for x in r   for y in range(x,b)   for z in r    if x**2 + y**2 == z**2)
    return list(values)