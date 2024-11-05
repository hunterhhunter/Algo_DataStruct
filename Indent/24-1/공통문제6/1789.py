inp = int(input())
n = 1
result = 0

while n*(n+1)/2 <= inp: # n까지의 합 공식
    n += 1
print(n-1)