n = int(input())

# i - int(sqrt(i))**2 를 참조 

dp = [0 for _ in range(n+1)]
dp[1] = 1

# n * sqrt(n)의 풀이
# 일단 dp[i]에 i와 가장 가까운 제곱수로 표현되는 경우의 수 할당
# 그 후 1부터 int(i**2)+1까지 순회하며 다른 경우 찾기기

for i in range(2, n+1):
    tmp = i**0.5
    if tmp%1 == 0:
        dp[i] = 1
    else:
        # 5 = 4 + 1
        dp[i] = dp[int(tmp)**2] + dp[i - int(tmp)**2]
        for j in range(1, int(tmp)+1):
            dp[i] = min(dp[i], dp[j**2] + dp[i-j**2])

print(dp[n])