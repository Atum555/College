def add(n1:str, n2:str) -> str:
    point1 = n1.find(".")
    point2 = n2.find(".")
    n1 = "0" * (point2-point1) + n1
    n2 = "0" * (point1-point2) + n2
    n1 = n1 + "0" * (len(n2)-len(n1))
    n2 = n2 + "0" * (len(n1)-len(n2))
    carry = 0
    result = ""
    for i in range(-1, -len(n1)-1, -1):
        if n1[i] == ".": result = "." + result; continue
        result = str((int(n1[i]) + int(n2[i]) + carry) % 10) + result
        carry = (int(n1[i]) + int(n2[i]) + carry) // 10
    if carry > 0: result = str(carry) + result
    if result[0] == "0": 
        for i in range(len(result)):
            if result[i] != "0": result = result[i:]; break
    if result[-1] == "0":
        for i in range(-1,-len(result)-1,-1):
            if result[i] != "0": result = result[:i+1]; break
    if result[0] == ".": result = "0" + result
    if result[-1] == ".": result += "0"
    return result