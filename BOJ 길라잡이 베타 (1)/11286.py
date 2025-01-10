# MinHeap을 구현하는 것
# BottomUp 방식으로 구현해보고자 한다.

tree = [0 for _ in range(100000)]
ptr = 0
n = int(input())

def swap(x1, x2):
    global tree
    tree[x1], tree[x2] = tree[x2], tree[x1]

def bottomUp(tmp_ptr):
    global ptr, tree
    parent = tmp_ptr//2

    if tree[parent] == 0:
        swap(tmp_ptr, parent)
        bottomUp(parent)
    if abs(tree[tmp_ptr]) < abs(tree[parent]):
        swap(tmp_ptr, parent)
        bottomUp(parent)
    elif abs(tree[tmp_ptr]) == abs(tree[parent]):
        if tree[tmp_ptr] < tree[parent]:
            swap(tmp_ptr, parent)
            bottomUp(parent)
        else:
            return
    else:
        return

def topDown(tmp_ptr):
    global ptr, tree
    left = tmp_ptr * 2
    right = tmp_ptr * 2 + 1

    if 


def insert(x):
    global ptr, tree
    tree[ptr] = x
    bottomUp(ptr)
    ptr += 1

def delete():
    global ptr, tree
    if tree[0] == 0:
        print(0)
        return
    print(tree[0])
    tree[0] = 0
    ptr -= 1
    swap(0, ptr)
    ptr -= 1
    bottomUp(ptr)


for _ in range(n):
    command = int(input())
    if command != 0:
        insert(command)
    else:
        delete()