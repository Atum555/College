def knapsack(money:int, products:dict, wishlist:dict, sub:bool = False):
    results = []
    for product in wishlist:
        tempMoney, tempWishlist = money, wishlist.copy()

        tempMoney -= products[product]
        if tempMoney < 0: continue
        tempWishlist[product] -= 1
        if tempWishlist[product] == 0: del tempWishlist[product]

        res = knapsack(tempMoney, products, tempWishlist, sub=True)
        if res: 
            bought, tempMoney = res
            if bought.get(product): bought[product] += 1
            else: bought[product] = 1
        else: bought = {product: 1}
        results.append((bought, tempMoney))

    if not results: return results
    if sub: return sorted(results, key=lambda x: x[1])[0] 
    return sorted(results, key=lambda x: x[1])[0][0]