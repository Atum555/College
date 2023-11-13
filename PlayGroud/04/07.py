def collatz(n):
    n = int(n)
    r = ""
    while True:
        r += str(int(n)) + ","
        if n == 1: break
        if n % 2 == 0: n /= 2
        else: n *= 3; n += 1
    return r[:-1]