import sys
sinput = sys.stdin.readline

n, k = list(map(int, sinput().split()))
dptable = [[0 for _ in range(k+1)] for _ in range(n+1)] # 핵심인듯?
# x축으로는 담을 수 있는 무게만큼, y축은 물건 개수만큼 만들어서
# 담을 수 있는 무게의 물건이 나오면 x축으로 무게만큼 뒤로 가서 전 반복의 x축을 무게만큼 뒤로 가서
# 그 때의 최댓값과 현재 가지는 물건의 가치를 저장하는게 핵심인듯?
weights = [[0, 0]]

for _ in range(n):
    weights.append(list(map(int, sinput().split())))

for i in range(1, n+1):
    for j in range(1, k+1):
        weight = weights[i][0]
        valu = weights[i][1]
        if weight > j: # 담을 수 없으면
            dptable[i][j] = dptable[i-1][j]
        else:
            dptable[i][j] = max(dptable[i-1][j], dptable[i-1][j-weight] + valu)
print(dptable[n][k])