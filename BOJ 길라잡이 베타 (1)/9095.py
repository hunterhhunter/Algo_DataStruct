n = int(input())

# 초깃값 1, 2, 3만 잘 설정해주면 규칙성을 가진다. 전형적 DP문제

lst = [0 for _ in range(12)]
lst[1], lst[2], lst[3] = 1, 2, 4
for i in range(4, len(lst)):
    lst[i] = lst[i-3] + lst[i-2] + lst[i-1]

for _ in range(n):
    inp = int(input())
    print(lst[inp])