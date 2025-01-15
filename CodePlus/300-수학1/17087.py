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

jibhab = set()

for i in range(n):
    jibhab.add(uclid(lst[0], lst[i]))
print(min(jibhab))