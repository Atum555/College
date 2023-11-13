def summary_ranges(s:str) -> int:
    sArr = s.split(",")
    lastSeen = sArr[0]
    result = []
    while True:
        if not len(sArr): break
        if len(sArr) > 1 and str(int(lastSeen)+1) == sArr[1]:
            lastSeen = sArr[1]
            sArr.pop(1)
        else:
            if sArr[0] == lastSeen: result.append(lastSeen)
            else: result.append(f"{sArr[0]}->{lastSeen}")
            sArr.pop(0)
            try: lastSeen = sArr[0]
            except: return ",".join(result)

print(summary_ranges('0,1,2,3,4,5,7,10,11,20,21'))