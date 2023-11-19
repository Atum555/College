h = float(input())
m = float(input())
h = (h + 6 + (m + 51) // 60) % 24
m = (m + 51) % 60
print("{:02.0f}".format(h) + ":" + "{:02.0f}".format(m))