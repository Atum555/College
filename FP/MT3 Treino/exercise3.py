def lfsr(n:str):
    s = ""
    a = n
    while True:
        n = str(int(n[-1]) ^ int(n[-2])) + n
        s += n[-1]
        n = n[:-1]
        if a == n: break
    return s