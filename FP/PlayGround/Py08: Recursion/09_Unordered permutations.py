def permutations(atuple:tuple):
    if len(atuple) == 1: return {atuple}
    if len(atuple) == 2: return {atuple, (atuple[1], atuple[0])}
    premut = permutations(atuple[1:])
    result = set()
    for i in range(len(atuple)):
        for x in premut:
            result.add(tuple(list(x[:i]) + [atuple[0]] + list(x[i:])))
    return result