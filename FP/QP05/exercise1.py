def rm_letter_rev(ch:str, s:str) -> str:
    while s.find(ch) != -1:
        s = s[:(s.find(ch))] + s[(s.find(ch))+1:]
    return s[::-1]