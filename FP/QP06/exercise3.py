def change(amount:int) -> list:
    result = []
    # 200, 100, 50, 20, 10, 5, 2, 1
    while amount >0:
        for x in [200,100,50,20,10,5,2,1]: 
            if 0<= amount - x: amount -=x; result.append(x); break

    return result