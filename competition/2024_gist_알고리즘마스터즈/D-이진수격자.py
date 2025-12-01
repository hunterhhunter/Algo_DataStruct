import sys
sinput = sys.stdin.readline

n = int(sinput())
lst = [list(map(str, sinput().split())) for _ in range(n)]
dp = [["" for _ in range(n)] for _ in range(n)]
dp[0][0] = lst[0][0]
for i in range(n):
    for j in range(n):
        try:
            if i < 1:
                dp[i][j] = str(dp[i][j-1]+lst[i][j])
            elif j < 1:
                dp[i][j] = str(dp[i-1][j] + lst[i][j])
            else:
                dp[i][j] = str(max(int(dp[i-1][j]+lst[i][j]), int(dp[i][j-1]+lst[i][j])))
        except:
            continue

res = dp[-1][-1][::-1]
ss = 0
for i in range(len(res)):
    ss += int(res[i]) * (2**i)
print(ss)