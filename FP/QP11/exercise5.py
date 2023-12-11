def longest_prefix(words:list):
    if len(words) == 1: return words[0]
    l1, l2 = longest_prefix(words[:len(words)//2]), longest_prefix(words[len(words)//2:])
    prefix = ""
    i = 0
    while True:
        if i == len(l1) or i == len(l2): break
        if l1[i] == l2[i]:
            prefix += l1[i]
            i += 1
        else: break
    return prefix