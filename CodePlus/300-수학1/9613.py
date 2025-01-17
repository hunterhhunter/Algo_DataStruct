import sys
from itertools import combinations
input = sys.stdin.readline

def uclid(a, b):
    while True:
        r = a % b
        if r == 0:
            return b
        a = b
        b = r

n = int(input())

for _ in range(n):
    ans = 0
    lst = list(map(int, input().split()))
    element = lst[1:]
    combi = list(combinations(element, 2))
    for each in combi:
        res = uclid(each[0], each[1])
        ans += res
    print(ans)