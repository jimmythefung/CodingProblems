def treeBottom(tree):
    level = dict()
    depth = -1
    maxDepth = -1

    # DFS Traversal
    i = 0
    while i < len(tree):
        e = tree[i]

        # Case 1: open paren
        if e == "(":
            depth+=1
            if depth > maxDepth:
                maxDepth = depth
            if depth not in level:
                level[depth] = []

        # Case 2: a number value
        if e.isdigit():
            a = i
            while tree[i] != " ":
                i+=1
            number = tree[a:i]
            level[depth].append( int(number) )

        # Case 3: close paren
        if e == ")":
            depth-=1

        i+=1

    return level[maxDepth-1]
            

    

tree = "(2 (7 (2 () ()) (6 (5 () ()) (11 () ()))) (5 () (9 (4 () ()) ())))"
print( treeBottom(tree) )
