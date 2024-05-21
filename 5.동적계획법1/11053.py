n = int(input())
lst = list(map(int, input().split()))

table = [1] * n
tmp_num = [lst[0]]
tmp_max = 1
prev_num = min(lst)

for i in range(1, n):
    
print(max(table))