def preorder(tree:tuple) -> list:
    arr = [tree[0]]
    if tree[1]: arr += preorder(tree[1])
    if tree[2]: arr += preorder(tree[2])
    return arr