def bagdiff(xs:list[int], ys:list[int]) -> list[int]:
    for item in ys:
        if item in xs: xs.remove(item)
    return xs