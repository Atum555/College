def msort(xs:list) -> list:
    if len(xs) < 2: return xs
    xs, ys = msort(xs[:len(xs)//2]), msort(xs[len(xs)//2:])

    result = []
    i = j = 0
    while i < len(xs) and j < len(ys):
        if xs[i] < ys[j]: 
            result.append(xs[i])
            i += 1
        else: 
            result.append(ys[j])
            j += 1
    result.extend(xs[i:])
    result.extend(ys[j:])
    return result