def map_filter_reduce(lst:list, f1, f2, f3) -> int:
    from functools import reduce
    return reduce(f3, map(f2, filter(f1, lst)))