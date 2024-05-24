n = int(input())
lst = list(map(int, input().split()))

table = [1 for _ in range(n)]

for i in range(n):
    tmp = lst[i]
    for j in range(i):
        if tmp > lst[j]:
            table[i] = max(table[i], table[j] + 1)

print(max(table))