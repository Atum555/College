# One-liner
import math
def comprehensions(i:int, j:int):  return list(filter(lambda x: x % 10 == 3 or x % 10 == 8, range(i,j+1))), tuple(map(lambda x: round(math.sqrt(x), 2), range(i,j+1))), dict(map(lambda x: (x, chr(x)), range(i,j+1)))

# Normal
import math
def comprehensions(i:int, j:int):
    interval = range(i,j+1)

    is3or8 = lambda x: x % 10 == 3 or x % 10 == 8
    theList = filter(is3or8, interval)
    theList = list(theList)

    def sqr(n:int):
        value = math.sqrt(n)
        result = round(value, 2)
        return result
    theTuple = map(sqr, interval)
    theTuple = tuple(theTuple)

    theDict = {x: chr(x) for x in interval}

    return (theList, theTuple, theDict)