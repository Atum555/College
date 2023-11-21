def variance(alist:list) -> float:
    avg = sum(alist)/len(alist)
    return round(sum(map(lambda x: (x-avg)**2, alist)) / len(alist), 3)