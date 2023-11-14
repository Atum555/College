def dogs(h_age):
    r = 0
    for x in range(1, h_age+1):
        if x == 1 or x == 2: r += 10.5; continue
        r += 4
    return r