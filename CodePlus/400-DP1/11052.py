n = int(input())
lst = list(map(int, input().split()))
dp = [[0 for _ in range(n+1)] for _ in range(n+1)]

for i in range(1, n+1):
    dp[i][i] = lst[i-1]

# 문제를 너무 어렵게 풀어버렸다. 1차원 배열로 n^2풀이도 가능할텐데...
# 2차원 배열로 선언해 푼게 문제이다.
for i in range(1, n+1):
    for j in range(1, n+1):
        dp[i][j] = max(dp[i-1][j]+dp[1][1], dp[i][j-1], dp[i][j], dp[(i//j)*j][j] + dp[i-((i//j)*j)][i-j], lst[j-1]*(i//j))

print(dp[n][n])