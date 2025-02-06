import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    size = int(input())
    lst = list()
    for _ in range(2):
        lst.append(list(map(int, input().split())))

    dp = [[0 for _ in range(size+1)] for _ in range(3)]
    dp[1][1], dp[2][1] = lst[0][0], lst[1][0]

    for i in range(2, size+1):
        for j in range(1, 3):
            if j == 1:
                dp[j][i] = max(lst[0][i-1] + dp[2][i-1], dp[1][i-1])
            else:
                dp[j][i] = max(lst[1][i-1] + dp[1][i-1], dp[2][i-1])
    print(max(dp[1][size], dp[2][size]))