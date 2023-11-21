n = int(input())
values = []
while n > 0:
    values.append(n % 10)
    n = n // 10
while len(values) > 0:
    print(int(str(values.pop()) + "0" * len(values)))