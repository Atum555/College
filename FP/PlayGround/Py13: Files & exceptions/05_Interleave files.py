def interleave(f1, f2):
    r = ""
    with open(f1, "r") as fa:
        with open(f2, "r") as fb:
            fal = fa.readlines()
            fbl = fb.readlines()
            for i in range(min(len(fal), len(fbl))):
                r += fal[i]
                r += fbl[i]
    return r