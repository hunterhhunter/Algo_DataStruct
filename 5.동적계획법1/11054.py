n = int(input())
lst = list(map(int, input().split()))

table = [1 for _ in range(1)]

for i in range(n):
    tmp = lst[i]
    