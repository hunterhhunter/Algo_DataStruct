n = [0 for _ in range(1000001)]

a = int(input())
n[1], n[2] = 1, 2

for i in range(3, a+1):
    n[i] = (n[i-1] + n[i-2])%15746

print(n[a])