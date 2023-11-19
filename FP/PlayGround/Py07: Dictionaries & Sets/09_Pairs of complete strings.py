def complete_pairs(set1:set, set2:set):
    result = set()
    for s1 in set1: 
        for s2 in set2:
            sT = s1 + s2
            if len({x for x in sT} ^ {chr(ord("a") + x) for x in range(26)}) == 0: result.add(sT)
    return result