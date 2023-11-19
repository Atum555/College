def academy_awards(alist:list):
    awards = {}
    for award, name in alist:
        if awards.get(name): awards[name] += 1
        else: awards[name] = 1
    return awards