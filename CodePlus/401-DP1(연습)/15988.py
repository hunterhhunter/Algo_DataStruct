n = int(input())
lst = []
for _ in range(n):
    lst.append(int(input()))
mx = max(lst)

# dp[i]는 각 숫자를 표현할 수 있는 경우의 수이나
# 1, 2, 3으로 표현할 때 중복이 가능하기에
# 1을 더할 수 있는 경우(dp[i-1]), 2를 더할 수 있는 경우(dp[i-2])
# 3을 더할 수 있는 경우(dp[i-3])
# 위의 모든 것을 더한 것이 dp[i]

dp = [0 for _ in range(mx+1)]
dp[1], dp[2], dp[3] = 1, 2, 4

for i in range(4, mx+1):
    dp[i] = dp[i-1]%1000000009 + dp[i-2]%1000000009 + dp[i-3]%1000000009

for each in lst:
    print(dp[each]%1000000009)