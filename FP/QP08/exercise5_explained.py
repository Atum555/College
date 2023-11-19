""" 
Code by: Cláudio Meireles && Diogopmac
"""

def soup_rec(matrix, word, line, col):
    # Esta função tem que dar return True caso seja possivel encontrar a palavra,
    # Ou False caso não seja.

    # Caso base, se não há mais letras a procurar, é porque encontrou a palavra toda!
    if len(word) <= 0: return True

    # É preciso procurar o resto da palavra nas posições:
    # Imediatamente em cima, em baixo, à frente ou atrás
    
    # ATENÇÃO: A posição em que estamos a procurar,
    # podem não existir, daí termos de verificar antes de as tentar acessar!
    n_lines = len(matrix)     # Nº de linhas
    n_cols = len(matrix[0])   # Nº de colunas

    if col-1 >= 0: # Verificar se a coluna atrás existe.
        if word[0] == matrix[line][col-1]: # Posição atrás
            return soup_rec(matrix, word[1:], line, col-1) # Procurar o resto da palavra apartir da nova posição
 
    if col+1 < n_cols: # Verificar se a coluna à frente existe.
        if word[0] == matrix[line][col+1]: # Posição à frente
            return soup_rec(matrix, word[1:], line, col+1) # Procurar o resto da palavra apartir da nova posição

    if line-1 >= 0: # Verificar se a linha acima existe.
        if word[0] == matrix[line-1][col]: # Posição em cima
            return soup_rec(matrix, word[1:], line-1, col) # Procurar o resto da palavra apartir da nova posição

    if line+1 < n_lines: # Verificar se a linha abaixo exite.
        if word[0] == matrix[line+1][col]: # Posição em baixo
            return soup_rec(matrix, word[1:], line+1, col) # Procurar o resto da palavra apartir da nova posição

    # Caso nenhuma dessas posições tenha a letra que estamos à procura,
    # e a palavra ainda tenha letras por procurar,
    # esta posição não contema a palavra e por isso damos return de False.
    return False



def soup(matrix, word):
    # Caso a palavra seja vazia a resposta é a primeira posição da matrix.
    if word == "": return "A1" 

    for line in range(len(matrix)):             # Procurar para cada linha.
        for col in range(len(matrix[0])):       # E dentro de cada linha, procurar para cada coluna.
            if matrix[line][col] == word[0]:    # Verificar se a entrada selecionada é igual à primeira linha.
                
                # Até aqui encontramos a primeira letra.
                # Precisamos agora de encontrar o resto
                # da palavra apartir do desta posição.

                # Chama-se a função recursiva, com o resto da palavra e a posição onde "estamos".
                result = soup_rec(matrix, word[1:], line, col)
                # A função recursiva deve-te dar simplesmente um True or False,
                # Dependendo se encontrou o resto da palvra ou não.

                if result:
                    # Caso seja True,
                    # Dás return das cordenadas onde encontraste a primeira letra.

                    return f"{ chr( ord('A') + line) }{ col+1 }" 
                    # Linha é a letra A + o index da linha em que estamos.
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

print(soup([['X', 'R', 'Z', 'B', 'H', 'A'], 
            ['K', 'A', 'S', 'I', 'G', 'O'], 
            ['J', 'O', 'T', 'C', 'A', 'N'], 
            ['F', 'S', 'R', 'H', 'T', 'U'], 
            ['D', 'P', 'O', 'O', 'X', 'F'], 
            ['Z', 'B', 'B', 'W', 'F', 'S']], ''))