n = int(input())
lst = list(map(int, input().split()))
lst.insert(0, 0)

dp = [lst[i]*(n//(i)) for i in range(1, n+1)]
dp.insert(0, 0)

for i in range(1, n+1):
    for j in range(1, i+1):
        dp[i] = min(dp[i], lst[j]+dp[i-j])

print(dp[n])