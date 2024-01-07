def division(a:int, b:int):
    try:
        return f"{a}/{b} = {a/b}"
    except ZeroDivisionError:
        return "can't divide by 0!"
    except TypeError:
        return "unsupported operand type(s) for division"