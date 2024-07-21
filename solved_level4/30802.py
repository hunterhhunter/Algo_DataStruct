n = int(input())

lst = list(map(int, input().split()))

t, p = map(int, input().split())

tsh = 0

for i in lst:
    tsh += (i-1) // t + 1

print(tsh)
print(n//p, n%p)