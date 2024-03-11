n, k = map(int, input().split())
lis = [i for i in range(1, n+1)]
visit = [False for _ in range(n+1)]
res = []

def ndm(n, depth, k):
    if depth == k:
        print(' '.join(map(str, res)))

    for i in range(1, n+1):
        if not visit[i-1]:
            res.append(i)
            visit[i-1] = True
            ndm(n, depth+1, k)
            visit[i-1] = False
            res.pop()

ndm(n, 0, k)