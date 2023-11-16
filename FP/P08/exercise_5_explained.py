def soup_rec(matrix, word, line, col):
    # Esta função tem que dar return True caso seja possivel encontrar a palavra,
    # Ou False caso não seja.

    # Caso base, se não há mais letras a procurar, é porque encontrou a palavra toda!
    if len(word) <= 0: return True

    # É preciso procurar o resto da palavra nas posições:
    # Imediatamente em cima, em baixo, à frente ou atrás
    
    # ATENÇÃO: A posição em que estamos a procurar,
    # podem não existir, daí termos de usar o try/except!
    # Podiamos verificar se as posições existem ou não,
    # mas assim é mais simples.
    try:
        if word[0] == matrix[line][col-1]: # Posição atrás
            return soup_rec(matrix, word[1:], line, col-1) # Procurar o resto da palavra apartir da nova posição
    except: pass
    
    try:
        if word[0] == matrix[line][col+1]: # Posição à frente
            return soup_rec(matrix, word[1:], line, col+1) # Procurar o resto da palavra apartir da nova posição
    except: pass
    
    try:
        if word[0] == matrix[line-1][col]: # Posição em cima
            return soup_rec(matrix, word[1:], line-1, col) # Procurar o resto da palavra apartir da nova posição
    except: pass

    try:
        if word[0] == matrix[line+1][col]: # Posição em baixo
            return soup_rec(matrix, word[1:], line+1, col) # Procurar o resto da palavra apartir da nova posição
    except: pass

    # Caso nenhuma dessas posições tenha a letra que estamos à procura,
    # e a palavra ainda tenha letras por procurar,
    # esta posição não contema a palavra e por isso damos return de False.
    return False



def soup(matrix, word):
    for line in range(len(matrix)):
        for col in range(len(matrix[0])):
            if matrix[line][col] == word[0]:
                # Até aqui o teu código encontrou a primeira letra.
                # Precisa agora de verificar se consegue encontrar o resto
                # da palavra apartir do desta posição.

                # Chamas a função recursiva, com o resto da palavra e a posição onde "estás".
                result = soup_rec(matrix, word[1:], line, col)
                # A função recursiva deve-te dar simplesmente um True or False,
                # Dependendo se encontrou o resto da palvra ou não.
                if result:
                    # Caso seja True,
                    # Dás return das cordenadas onde encontraste a primeira letra.
                    letters = {0: "A",
                               1: "B",
                               2: "C", # Dicionário que converte o número da linha
                               3: "D", # na letra correspondente.
                               4: "E",
                               5: "F"} 
                    return f"{letters[line]}{col+1}" 
                    # Coluna tens de somar 1, porque listas começam no 0
    
    # Caso a primeira letra nunca seja encontrada,
    # Ou caso seja encontrada mas não é possivel encontrar o resto da palavra.
    return None


#             0    1    2    3    4    5
print(soup([['X', 'R', 'Z', 'B', 'H', 'A'], 
            ['K', 'A', 'S', 'I', 'G', 'O'], # 1
            ['J', 'O', 'T', 'C', 'A', 'N'], # 2
            ['F', 'S', 'R', 'H', 'T', 'U'], # 3
            ['D', 'P', 'O', 'O', 'X', 'F'], # 4
            ['Z', 'B', 'B', 'W', 'F', 'S']], 'PORTO'))

print(soup([['X', 'R', 'Z', 'B', 'H', 'A'], 
            ['K', 'A', 'S', 'I', 'G', 'O'], 
            ['J', 'O', 'T', 'C', 'A', 'N'], 
            ['F', 'S', 'R', 'H', 'T', 'U'], 
            ['D', 'P', 'O', 'O', 'X', 'F'], 
            ['Z', 'B', 'B', 'W', 'F', 'S']], 'OASIS'))

print(soup([['X', 'R', 'Z', 'B', 'H', 'A'], 
            ['K', 'A', 'S', 'I', 'G', 'O'], 
            ['J', 'O', 'T', 'C', 'A', 'N'], 
            ['F', 'S', 'R', 'H', 'T', 'U'], 
            ['D', 'P', 'O', 'O', 'X', 'F'], 
            ['Z', 'B', 'B', 'W', 'F', 'S']], 'GATUNO'))

print(soup([['X', 'R', 'Z', 'B', 'H', 'A'], 
            ['K', 'A', 'S', 'I', 'G', 'O'], 
            ['J', 'O', 'T', 'C', 'A', 'N'], 
            ['F', 'S', 'R', 'H', 'T', 'U'], 
            ['D', 'P', 'O', 'O', 'X', 'F'], 
            ['Z', 'B', 'B', 'W', 'F', 'S']], 'TACOS'))