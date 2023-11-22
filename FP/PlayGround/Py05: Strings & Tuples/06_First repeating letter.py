def repeated_letter(s:str) -> str:
    for ch in s: 
        if s.count(ch) >1: return ch