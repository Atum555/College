def greatest(n:int):
    arr = []
    while True:
        if n == 0: break
        arr.append(n % 10)
        n //= 10
    arr.sort(reverse=True)
    for x in arr:
        n *= 10
        n += x
    return n