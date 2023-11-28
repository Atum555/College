def middle_square(number:int, digits:int, iterations:int) -> int:
    for _ in range(iterations):
        number **= 2
        numberL = [x for x in str(number)]
        while len(numberL) < digits*2:
            numberL.insert(0,"0")
        number = 0
        for i in range(int(digits*0.5), int(digits*1.5)):
            number *= 10
            number += int(numberL[i])
    return number