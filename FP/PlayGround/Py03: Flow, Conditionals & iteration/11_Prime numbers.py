def is_Prime(n):
    if n < 2: return False
    for x in range(2,n):
        if n % x == 0: return False
    return True

l = int(input())
t = int(input())
arr = []
for x in range(l,t+1):
    if is_Prime(x): arr.append(x)

print(f"Prime numbers between {l} and {t} are:", end="")
for x in arr:
    print("", x, end="")