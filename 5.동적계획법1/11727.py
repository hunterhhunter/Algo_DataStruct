n = int(input())

lst = [0 for _ in range(1001)]

lst[1], lst[2] = 1, 3

for i in range(3, n+1):
    if i%2 == 1:
        lst[i] = lst[i-1]*2-1
    else:
        lst[i] = lst[i-1]*2+1

print(lst[n]%10007)