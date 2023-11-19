def fight(heroes:list, villain:dict):
    for hero in heroes:
        if hero["category"] != villain["category"]: continue
        if hero["health"] >= villain["health"]:
            hero["score"] += 1
            return f"{hero['name']} defeated the villain and now has a score of {hero['score']}"
        villain["health"] -= hero["health"] /2
    return f"{villain['name']} prevailed with {villain['health']}HP left"