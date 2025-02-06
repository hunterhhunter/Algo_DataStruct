n = int(input())

dp = [0 for _ in range(n//2+1)]
dp[1] = 3

if n % 2 == 0:
    for i in range(n//2):