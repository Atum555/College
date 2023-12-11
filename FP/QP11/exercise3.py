def search_tree(key:str, tree:tuple, visited:tuple = ()):
    if tree == None: return None
    if tree[0] == key: return (tree[1], [*visited, tree[0]])

    if tree[2] and key < tree[0] and (result:= search_tree(key, tree[2], visited = (*visited, tree[0]))):
        return result
    
    if tree[3] and key > tree[0] and (result:= search_tree(key, tree[3], visited = (*visited, tree[0]))):
        return result