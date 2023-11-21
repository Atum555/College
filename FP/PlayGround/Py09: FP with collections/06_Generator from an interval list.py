def generator(intlist:list) -> list:
    from functools import reduce
    return iter(reduce(lambda x,y: x+y, map(lambda x: list(range(x[0],x[1]+1)), intlist)))