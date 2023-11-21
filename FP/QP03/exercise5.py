num1 = int(input())
num2 = int(input())

res = 0
while True:
    res *= 10 if num1 > 0 else 1
    res += num1 % 10
    num1 //= 10
    res *= 10 if num2 > 0 else 1
    res += num2 % 10
    num2 //= 10
    if num1 <= 0 and num2 <= 0: break
print(res)