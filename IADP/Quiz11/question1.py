full_name = input()
names = full_name.split()

result = ""

for i, name in enumerate(names):
    if name in ("de", "da", "das", "do", "das"): continue
    if (i != len(names) - 1): result += name[0] + '. '
    else: result += name

print(result)
