n = input()
nvn = bool(max([int(x not in "01234567") for x in n]))
n = n * (not nvn) + "0" * nvn
value = int(n, base=8)
print(nvn * "Not a valid number." + (not nvn) * str(value))