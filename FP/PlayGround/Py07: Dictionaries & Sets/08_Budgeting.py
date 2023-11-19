def budgeting(budget:int, products:dict, wishlist:dict):

    def total(wishlist, products):
        result = 0
        for item in wishlist: result += products[item] * wishlist[item]
        return result
    
    productsOrdered = sorted(products.items(), key=lambda x: x[1])
    while total(wishlist, products) > budget:
        for item, value in productsOrdered:
            if item in wishlist:
                wishlist[item] -= 1
                if wishlist[item] <= 0: del wishlist[item]
                break
    return wishlist