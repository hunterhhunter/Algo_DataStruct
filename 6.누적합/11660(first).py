import sys
sinput = sys.stdin.readline

n, m = list(map(int, sinput().split()))

lst = []

for i in range(n):
    tmplst = [0 for _ in range(n+1)]
    ss = list(map(int, sinput().split()))
    for j in range(1, n+1):
        tmplst[j] += ss[j-1]+tmplst[j-1]
    lst.append(tmplst)

for _ in range(m):
    su = 0
    dy, dx, ny, nx = list(map(int, sinput().split()))
    if dy == ny:
        print(lst[dy-1][nx]-lst[dy-1][dx-1])
    else:
        for i in range(dy-1, ny):
            su += lst[i][nx]-lst[i][dx-1]
        print(su)