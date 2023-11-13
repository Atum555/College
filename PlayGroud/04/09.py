def digits_average(n):
    while True:
        if n // 10 == 0: return int(n)
        new_n = 0
        while True:
            if n // 10 == 0: break
            n1 = n % 10
            n = n // 10
            n2 = n % 10
            n3 = (n1+n2)/2
            if n3 % 1 != 0: n3 //= 1; n3 += 1
            new_n *= 10
            new_n += n3
        n = new_n

digits_average(9434)