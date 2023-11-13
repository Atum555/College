def local_minima(alist:list) -> list:
    result = []
    for i in range(len(alist)):
        try: alist[i+2]
        except: break
        if 1 == alist[i:i+3].count(min(alist[i:i+3])): result.append(min(alist[i:i+3]))
    return result