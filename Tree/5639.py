import sys
sys.setrecursionlimit(10**9)

tree = {0:{'right': 0, "left": 0}}
parents = []
past = 0
cnt, root = 0, 0

while True:
    try:
        n = int(input())
        if cnt == 0:
            root = n
            parents.append(n)
        cnt += 1
    except:
        break

    if n == -1:
        break
    tree[n] = {'left': '.', 'right': '.'}
    
    if n < parents[-1]:
        tree[parents[-1]]['left'] = n
    else:
        for i in range(len(parents)-1, -1, -1):
            now = parents.pop()
            if now < n:
                past = now
                continue
            else:
                parents.append(now)
                parents.append(past)
                tree[past]['right'] = n
                break
        else:
            tree[past]['right'] = n
    
    parents.append(n)
    
def postOrder(tree, current_node):
    if tree[current_node]['left'] != '.':
        postOrder(tree, tree[current_node]['left'])
    if tree[current_node]['right'] != '.':
        postOrder(tree, tree[current_node]['right'])
    print(current_node)

del tree[0]
postOrder(tree, root)
# for i, j in tree.items():
#     print(i, j)