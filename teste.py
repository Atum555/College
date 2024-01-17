import functools, time, datetime

def timer(func):    
    """Prints execution time for a function."""
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        sTime = time.time_ns()
        print(f"Starting {func.__name__!r} with args: {args} {kwargs}.'")

        result = func(*args, **kwargs)
        
        runTime = time.time_ns() - sTime
        print(f"Done executing in {runTime}ns {func.__name__!r} with args: {args} {kwargs}.")
        return result
    return wrapper  


def memorize(func):
    lista = {}
    
    @functools.wraps(func)
    def wrapper(*args):
        if args in lista: 
            print(f"Already done, returning memory: {args}")
            return lista[args]
        else:
            print(f"Not in memory: {args}")
            value = func(*args)
            lista[args] = value
            return value
    return wrapper


@memorize
def fibonacci(n:int): 
    return 1 if n < 2 else fibonacci(n-1) + fibonacci(n-2)


def infinite_sequence():
    num = 0
    while True:
        yield num
        num += 1


def gcd_Euclid(a:int, b:int):
    assert isinstance(a, int)
    assert isinstance(b, int)
    if b == 0:
        return a

    return gcd_Euclid(b, a%b)