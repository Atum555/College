def bagdiff(xs:list, ys:list) -> list:
    for item in ys:
        if item in xs: xs.remove(item)
    return xs