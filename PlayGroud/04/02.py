def count_chars(st,ch):
    count = 0
    for x in st:
        if x == ch: count += 1
    if count == 0: count = -1
    return count