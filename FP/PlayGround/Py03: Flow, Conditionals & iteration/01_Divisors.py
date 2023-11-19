n = int(input())

c = 0
for i in range(1,n+1): c += i if n%i == 0 else 0

print(c)