def permuta(alist:list, step:int = 0):
    if step == len(alist): return alist
    results = []
    for i in range(len(alist)):
        tList = alist.copy()
        if i < step: continue
        tList[i], tList[step] = tList[step], tList[i]
        if step == len(alist)-1: results.append(tList)
        else: results += permuta(tList, step=step+1)
    return results