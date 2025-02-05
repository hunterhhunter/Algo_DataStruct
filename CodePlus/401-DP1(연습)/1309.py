n = int(input())
# 해법은 맞을 수 있으나 더 쉽게 풀 수 있음 
# 이 코드는 메모리 초과나는 코드드

# dp = [[0 for _ in range(i+1)] for i in range(n, -1, -1)]
# dp[0][0] = 1

# for i in range(1, n+1):
#     dp[i][i] = 2
#     dp[0][i] = 1

# for i in range(2, n+1):
#     for j in range(1, i):
#         dp[j][i] = dp[j][i-1]%9901 + dp[j-1][i-1]%9901 + dp[j-1][i-2]%9901

# res = 0
# for i in range(n+1):
#     res += dp[i][n]

# print(res%9901)

# dp[i]의 규칙성을 발견
#p[j][i] = dp[j][i-1]%9901 + dp[j-1][i-1]%9901 + dp[j-1][i-2]%9901
# 이 풀이도 있었으나
# 더 빠르고 좋은 규칙성 발견

dp = [0 for _ in range(n+1)]
dp[0], dp[1] = 1, 3

for i in range(2, n+1):
    dp[i] = (dp[i-1]*2)%9901 + dp[i-2]%9901

print(dp[n]%9901)