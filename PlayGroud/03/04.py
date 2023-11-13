n = input()

r = bool(
    ((abs(int(n[0]) - int(n[1])) - 1) * (abs(int(n[0]) - int(n[1])) - 9))
    +
    ((abs(int(n[len(n)-2]) - int(n[len(n)-1])) - 1) * (abs(int(n[len(n)-2]) - int(n[len(n)-1])) - 9))
    )

print((abs(r-1))* "Looping number" + r * "Not a looping number")