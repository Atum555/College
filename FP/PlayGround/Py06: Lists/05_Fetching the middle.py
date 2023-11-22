def fetch_middle(llist:list) -> list:
    result = []
    for l in llist:
        if len(l) % 2: result.append(l[len(l)//2])
        else: result.append((l[len(l)//2-1] + l[len(l)//2]) /2)
    return result