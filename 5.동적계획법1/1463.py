lst = [0 for _ in range(1000001)]
n = int(input())

lst[1], lst[2], lst[3] = 0, 1, 1
for i in range(4, n+1):
    lst[i] = lst[i-1] + 1
    if i%2 == 0:
        lst[i] = min(lst[i//2]+1, lst[i])
    if i%3 == 0:
        lst[i] = min(lst[i//3]+1, lst[i])

print(lst[n])