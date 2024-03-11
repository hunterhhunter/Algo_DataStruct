n = int(input())
res = 0
lis = [0] * n

def is_attacked(x):
    for i in range(x):
        if lis[x] == lis[i] or abs(lis[x] - lis[i]) == abs(x - i):
            return False
    return True

def nqueen(depth):
    global res

    if depth == n:
        res += 1
        return
    else:
        for i in range(n):
            lis[depth] = i
            if is_attacked(depth):
                nqueen(depth+1)
nqueen(0)
print(res)