file_name1 = input("Filename 1:")
file_name2 = input("Filename 2:")

with open(file_name1) as f1:
    for first_name in map(str.strip, f1.readlines()):
        with open(file_name2) as f2:
            for second_name in map(str.strip, f2.readlines()):
                print(first_name, second_name)
