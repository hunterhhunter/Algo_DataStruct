n = int(input())

tree = {}

for _ in range(n):
    lst = input().split()
    tree[lst[0]] = {'left': lst[1], 'right': lst[2]}

def preOrder(tree, current_node):
    child = ['left', 'right']
    print(current_node, end='')
    for i in child:
        if tree[current_node][i] != '.':
            preOrder(tree, tree[current_node][i])

def inOrder(tree, current_node):
    if tree[current_node]['left'] != '.':
        inOrder(tree, tree[current_node]['left'])
    print(current_node, end='')
    if tree[current_node]['right'] != '.':
        inOrder(tree, tree[current_node]['right'])

def postOrder(tree, current_node):
    if tree[current_node]['left'] != '.':
        postOrder(tree, tree[current_node]['left'])
    if tree[current_node]['right'] != '.':
        postOrder(tree, tree[current_node]['right'])
    print(current_node, end='')

preOrder(tree, 'A')
print()
inOrder(tree, 'A')
print()
postOrder(tree, 'A')