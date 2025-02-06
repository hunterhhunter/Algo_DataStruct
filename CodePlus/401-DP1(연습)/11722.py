n = int(input())

lst = list(map(int, input().split()))
dp = [1 for _ in range(n)]

for i in range(1, n):
    tmp = lst[i]
    for j in range(i):
        if tmp < lst[j]:
            dp[i] = max(dp[j] + 1, dp[i])

print(max(dp))