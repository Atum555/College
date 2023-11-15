def permutations(string:str)-> list:
    if len(string) <2 : return [string]

    result = []
    for i,letter in enumerate(string):                          # Fazer um Loop por todos os caracteres 
        string_without_l = string[:i]+string[i+1:]              # String without a letra do loop
        permut_of_sub_string = permutations(string_without_l)   # Lista de permutações da sub String (String exceto a lettra atual do loop)
        for permutation in permut_of_sub_string:
            result.append(letter+permutation)       # Adicionar "letra"+"resultado" à lista dos resultados

    return result