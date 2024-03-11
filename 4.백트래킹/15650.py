# n, m = map(int, input().split())

# visit = [False for _ in range(n+1)]
# res = []

# def ndm(n, k):
#     if len(res) == k:
#         print(' '.join(map(str, res)))
#         return

#     for i in range(1, n+1):
#         if not visit[i]:
#             res.append(i)
#             visit[i] = True
#             ndm(n, k)
#             res.pop()
#             visit[i+1:] = [False for _ in range(len(visit[i+1:]))]
# ndm(n, m)

n, m = map(int, input().split())

visit = [False] * (n + 1)
res = []

def ndm(index, cnt):
    if cnt == m:
        print(' '.join(map(str, res)))
        return

    for i in range(index, n + 1):
        if not visit[i]:
            res.append(i)
            visit[i] = True
            ndm(i + 1, cnt + 1)
            res.pop()
            visit[i] = False

ndm(1, 0)
