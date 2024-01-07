def longest(filename:str):
    import functools
    with open(filename, "r") as f:
        r = (sorted(functools.reduce(lambda x,y: [*x, *y], map(lambda x: x.split(), f)), key=lambda x: len(x)))[-1]
    return r