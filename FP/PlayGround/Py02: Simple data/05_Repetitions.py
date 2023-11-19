s = input()
r = ""
for x in range(int(input())):
    r += s
    r += "-"
print(r.rstrip("-"))