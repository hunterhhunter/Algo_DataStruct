from itertools import combinations
n, s = map(int, input().split())

def uclid(a, b):
    while True:
        r = a % b
        if r == 0:
            return b
        a = b
        b = r

lst = list(map(int, input().split()))

for i in range(n):
    lst[i] = abs(s - lst[i])

# 여러 수의 최대공약수는 앞 2개의 최대공약수와 뒤의 수의 최대공약수이다.
# 즉 순회하며 계속 최대공약수를 찾아주면 된다는 얘기
ans = lst[0]
for i in range(1, n):
    ans = uclid(ans, lst[i])
    if ans == 1:
        break
print(ans)