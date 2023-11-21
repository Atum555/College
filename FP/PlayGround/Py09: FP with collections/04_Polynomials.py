def evaluate(a:list,x:int) -> int:
    from functools import reduce
    return reduce(lambda x,y: x+y, map(lambda a: a[1]*x**a[0], enumerate(a)))