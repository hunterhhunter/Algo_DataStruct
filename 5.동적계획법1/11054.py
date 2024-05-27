n = int(input())
lst = list(map(int, input().split()))

table1 = [1 for _ in range(n)] # 테이블 두 개 선언해서
table2 = [1 for _ in range(n)] # 앞으로, 뒤로 순회 후 더하기
res = [0 for _ in range(n)]
if n > 2:
    if lst[-1] < lst[-2]:
        table2[-2] = 2
for i in range(n):
    tmp = lst[i]
    for j in range(i):
        if tmp > lst[j]:
            table1[i] = max(table1[j]+1, table1[i])
        if lst[n-i-1] > lst[n-j-1]:
            table2[n-i-1] = max(table2[n-j-1]+1, table2[n-i-1])

for i in range(n):
    res[i] = table1[i] + table2[i] - 1 # 처음에 둘 다 1로 선언했기에 -1을 해줘야함

print(max(res))