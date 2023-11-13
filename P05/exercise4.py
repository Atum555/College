def multi(g:tuple) -> tuple:
    count = {}
    for x in g:
        if f"{x[0]}{x[1]}" in count: count[f"{x[0]}{x[1]}"] += 1
        else: count[f"{x[0]}{x[1]}"] = 1
    result = ()
    for x in count:
        result += ((
            int(x[0]) if x[0].isnumeric() else x[0],
            count[x],
            int(x[1]) if x[1].isnumeric() else x[1]
            ),)
    return result