def camel_case(phrase:str) -> str:
    camel = False
    result = ""
    for x in phrase:
        if x.isalpha():
            result += x.lower() if not camel else x.upper()
            camel = False
        else:
            camel = True
    return result