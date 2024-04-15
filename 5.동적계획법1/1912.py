import sys
sinput = sys.stdin.readline

a = int(sinput())
lst = list(map(int, sinput().split()))
mx = lst.copy()
mx[0] = lst[0]

for i in range(1, a):
    mx[i] = max(lst[i], lst[i] + mx[i-1])

ma = max(mx)
print(ma)