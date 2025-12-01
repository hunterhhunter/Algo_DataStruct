import sys
sinput = sys.stdin.readline

def howmuch(n):
    how1, how2 = 0, 0
    f = n
    for i in range(9):
        if 2**i < f:
            continue
        else:
            how1 = i-1
            break
    f -= 2**how1
    for i in range(9):
        if 2**i < f:
            continue
        else:
            how2 = i
            break
    f -= 2**how2
    if f == 0:
        return how1, how2
    else:
        return False, False

n = int(sinput())

lst = list(map(int, sinput().split()))
res = int(sinput())
result = [i for i in range(8)]
for i in lst:
    a, b = howmuch(i)
    tmp = 0
    if a:
        idx1 = result.index(a)
        idx2 = result.index(b)
        tmp = result[idx1]
        result[idx1] = result[idx2]
        result[idx2] = tmp
print(result.index(res))