def count_exceptions(f, n1:int, n2:int):
    c = 0
    for x in range(n1, n2+1):
        try:
            f(x)
        except:
            c += 1
    return c