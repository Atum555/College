def pattern_hunting(l1:list, l2:list, p:str) -> list:
    result:list[str] = []
    for i in range(len(l1)):
        if p in l1[i]: result.append(l2[i])
    for i in range(len(l2)):
        if p in l2[i]: result.append(l1[i])
    return list(reversed(sorted(result)))