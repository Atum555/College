def pattern_hunting(l1:list[str], l2:list[str], p:str) -> list[str]:
    result:list[str] = []
    for i in range(len(l1)):
        if p in l1[i]: result.append(l2[i])
    for i in range(len(l2)):
        if p in l2[i]: result.append(l1[i])
    return list(reversed(sorted(result)))