n, m1 = map(int, input().split())
lst1, lst2 = [], []

for _ in range(n):
    lst1.append(list(map(int, input().split())))

m2, k = map(int, input().split())

res = [[0 for _ in range(k)] for _ in range(n)]

for _ in range(m2):
    lst2.append(list(map(int, input().split())))

for i in range(n):
    for j in range(k):
        tmp = 0
        for l in range(m1):
            tmp += lst1[i][l] * lst2[l][j]
        res[i][j] = tmp

for i in res:
    print(*i)