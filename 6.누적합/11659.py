import sys
input = sys.stdin.readline
n, m = map(int, input().split())
lis = list(map(int, input().rstrip().split()))
hap = [0]
temp = 0
for i in lis:
    temp += i
    hap.append(temp)


for _ in range(m):
    a, b = map(int, input().split())
    print(hap[b] - hap[a-1])