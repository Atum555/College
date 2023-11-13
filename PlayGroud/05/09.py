def greatest_member(a:tuple):
    def getScore(s:str) -> int: return sum([ord(x) for x in s])
    def handleTuple(t) -> int:
        subTotal = 0
        for x in t:
            if type(x) == str: subTotal += getScore(x)
            else: subTotal += handleTuple(x)
        return subTotal
    points = []
    for x in a:
        if type(x) == str: points.append(getScore(x))
        else: points.append(handleTuple(x))
    return a[points.index(max(points))]