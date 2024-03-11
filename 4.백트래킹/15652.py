n, m = map(int, input().split())
res = []

def ndm(idx, depth):
    if depth == m:
        print(*res)
        return

    for i in range(1, n+1):
        res.append(i)
        if i >= res[idx-1]:
            idx += 1
            ndm(idx, depth+1)
            idx -= 1
        else:
            pass
        res.pop()

ndm(0, 0)