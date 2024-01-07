def diff(filename1:str, filename2:str):
    with open(filename1, "r") as f1, open(filename2, "r") as f2:
        fl1 = f1.readlines()
        fl2 = f2.readlines()
    r = ""
    i2 = -1
    for i in range(len(fl1)):
        if fl1[i] not in fl2:
            r += f"- {fl1[i]}"
            continue
        r += ("".join(map(lambda x: f"+ {fl2[x]}", range(i2+1, fl2.index(fl1[i])))))
        i2 = i
    r += "".join(map(lambda x: f"+ {fl2[x]}", range(i2+1, len(fl2))))
    return r