def triplet(tup:tuple) -> tuple:
    for x in range(len(tup)):
        for y in range(x+1,len(tup)):
            for z in range(y+1, len(tup)):
                if not tup[x]+tup[y]+tup[z]: return (tup[x],tup[y],tup[z])
    return tuple()