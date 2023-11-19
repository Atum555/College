def change(money:float) -> dict:
    coins = [2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01] 
    dic = {2:0, 1:0, 0.5:0, 0.2:0, 0.1:0, 0.05:0, 0.02:0, 0.01:0}
    for coin in coins:
        while money >= coin:
            money = round(money - coin,2)
            dic[coin] += 1
    return dic