n = int(input())

lst = []

for _ in range(n):
    lst.append(int(input()))
mx = max(lst)
dp = [[0 for _ in range(mx+1)] for _ in range(4)]
dp[1][0], dp[1][1], dp[2][2], dp[3][3] = 1, 1, 1, 1

for i in range(3, mx+1):
    for j in range(1, 4):
        if j == 1:
            # 1을 붙일 수 있는 경우
            dp[j][i] = dp[2][i-1]%1000000009 + dp[3][i-1]%1000000009
        elif j == 2:
            # 2를 붙일 수 있는 경우
            dp[j][i] = dp[1][i-2]%1000000009 + dp[3][i-2]%1000000009
        elif j == 3:
            # 3을 붙일 수 있는 경우
            dp[j][i] = dp[1][i-3]%1000000009 + dp[2][i-3]%1000000009

for each in lst:
    print((dp[1][each]+dp[2][each]+dp[3][each])%1000000009)