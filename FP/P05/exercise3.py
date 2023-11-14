def mask_data(data:str, n_characters:int, position:str) -> str:
    if not n_characters: return data
    n_characters = abs(n_characters)
    position = True if position=="begin" else False
    return "*" * n_characters + data[n_characters:] if position else data[:-n_characters] + "*" * n_characters