n, m = map(int, input().split())
res = []

def ndm(n, depth):
    if depth == m:
        print(*res)
        return

    for i in range(1, n+1):
        res.append(i)
        ndm(n, depth+1)
        res.pop()

ndm(n, 0)