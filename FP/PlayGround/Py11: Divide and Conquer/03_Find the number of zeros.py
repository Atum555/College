def count_zeros(f):
    l = f()
    p = len(l)//2
    r = [0, len(l)]

    while True:
        if l[p-1] == 1 and l[p] == 0: break
        if l[p] == 1:       r[0] = p
        elif l[p-1] == 0:   r[1] = p
        p = (r[0] + r[1]) // 2

    return len(l) - p