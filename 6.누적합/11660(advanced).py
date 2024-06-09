import sys
sinput = sys.stdin.readline

n, m = list(map(int, sinput().split()))

lst = [list(map(int, sinput().split())) for _ in range(n)]

dptable = [[0]*(n+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        dptable[i][j] = dptable[i][j-1] + dptable[i-1][j] - dptable[i-1][j-1] + lst[i-1][j-1]

for _ in range(m):
    x1, y1, x2, y2 = map(int, sinput().split())
    ans = dptable[x2][y2] - dptable[x2][y1-1] - dptable[x1-1][y2] + dptable[x1-1][y1-1]

    print(ans)