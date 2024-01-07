def bitonic_point(f):
    l = f()
    p = len(l)//2
    r = [0, len(l)]

    while True:
        if l[p-1] < l[p] and l[p] > l[p+1]: break
        if l[p-1] < l[p] < l[p+1]:          r[0] = p
        elif l[p-1] > l[p] > l[p+1]:        r[1] = p
        p = (r[0] + r[1]) // 2

    return l[p]