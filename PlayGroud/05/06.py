def repeated_letter(s:str) -> str | None:
    for ch in s: 
        if s.count(ch) >1: return ch