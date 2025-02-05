n = int(input())

dp = [[1 for _ in range(10)] for _ in range(n+1)]

# 2차원 배열 선언
# dp[i][j]가 의미하는 바는 i길이의 오르막 문자열의 끝이 j로 끝나는 경우의 수수

for i in range(2, n+1):
    for j in range(1, 10):
        tmp = 0
        for k in range(j+1):
            tmp += dp[i-1][k]%10007
        dp[i][j] = tmp
res = 0

for i in range(10):
    res += dp[n][i]

print(res%10007)