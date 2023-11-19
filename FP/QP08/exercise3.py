def max_path(tree:tuple) -> int:
    if type(tree) == int: return tree
    left = tree[1] + max_path(tree[0])
    right = tree[1] + max_path(tree[2])
    return max(left, right)