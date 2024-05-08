n = int(input())
lst = [[1 for _ in range(10)] for _ in range(101)]
lst[1][0] = 0

for i in range(2, n+1):
    for j in range(10):
        if j == 0:
            lst[i][j] = lst[i-1][1]
            continue
        if j == 9:
            lst[i][j] = lst[i-1][8]
            continue
        else:
            lst[i][j] = lst[i-1][j-1] + lst[i-1][j+1]

print(sum(lst[n])%1000000000)