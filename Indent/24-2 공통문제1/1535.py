n = int(input())
L = [0] + [int(x) for x in input().split()]
J = [0] + [int(x) for x in input().split()]

dptable = [[0 for _ in range(101)] for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, 101):
        if L[i] <= j:
            dptable[i][j] = max(dptable[i-1][j], dptable[i-1][j-L[i]]+J[i])
        else:
            dptable[i][j] = dptable[i-1][j]

print(dptable[n][99])