def list_paths(dirtree:tuple, upper:str = ""):
    dirs = []
    for sub in dirtree[1]:
        if type(sub) == str:
            dirs.append(f"{upper}{'/' if upper else ''}{dirtree[0]}/{sub}")
        else:
            for d in list_paths(sub, f"{upper}{'/' if upper else ''}{dirtree[0]}"):
                dirs.append(d)
    return dirs