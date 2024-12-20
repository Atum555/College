file_name1 = input("Filename 1:")
file_name2 = input("Filename 2:")

line1 = ""
line2 = ""
with open(file_name1) as f1:
    with open(file_name2) as f2:
        while True:
            line1 = f1.readline().strip()
            line2 = f2.readline().strip()
            if line1 == '' and line2 == '': break
            if line1 == "": line1 = '0'
            if line2 == "": line2 = '0'
            print((float(line1) + float(line2)) / 2)
