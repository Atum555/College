def count_until(tup:tuple) -> int:
    count = 0
    for x in tup:
        if type(x) == tuple: return count
        count += 1
    return -1