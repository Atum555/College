r = 0
for i in range(int(input())):
    r += (((i + 1) % 3 == 0) or ((i + 1) % 5 == 0)) * (i + 1) 
print(r)