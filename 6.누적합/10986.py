n, m = map(int, input().split())
lst = list(map(int, input().split()))
sum_of_lst = [0]
ans = 0
tmp = 0

for i in lst:
    sm = i+sum_of_lst
    sum_of_lst.append(i+sum_of_lst[-1])

