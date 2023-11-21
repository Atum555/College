num = int(input())
rev_num = 0
while True:
    rev_num *= 10
    rev_num += num % 10
    num //= 10
    if num <= 0: break
print(rev_num)