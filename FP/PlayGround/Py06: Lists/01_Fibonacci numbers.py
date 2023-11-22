def fib(b:int) -> list:
    result = []
    while len(result)<b:
        if len(result) == 0: result.append(0)
        elif len(result) < 3: result.append(1)
        else: result.append(result[-2] + result[-1])
    return result