num = int(input())
if num < 3: exit()

# EVEN
if num % 2:
    for i in range(num):
        if i == num // 2: print("#" * (num // 2) + "0" + "#" * (num // 2))
        else: print("#" * num)
# ODD
else:
    for i in range(num):
        if i == num // 2 or i + 1 == num // 2: print("#"*((num-2)//2) + "00" + "#"*((num-2)//2))
        else: print("#" * num)