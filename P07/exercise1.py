def switch_dict(adict:dict) -> dict:
    reversedDict = {}
    for key in adict:
        if not reversedDict.get(adict[key]):            reversedDict[adict[key]] = [key]; continue
        reversedDict[adict[key]].append(key)
    return reversedDict