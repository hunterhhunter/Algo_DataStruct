import sys
sinput = sys.stdin.readline

n = int(sinput())
lst = [0]
res = []
eat_previous_drinks, not_previous_drinks = [0 for _ in range(n+1)], [0 for _ in range(n+1)]
for _ in range(n):
    lst.append(int(sinput()))

eat_previous_drinks[1], eat_previous_drinks[2] = lst[1], lst[1] + lst[2]
not_previous_drinks[1], not_previous_drinks[2] = lst[1], lst[2]
res.append(max(eat_previous_drinks[1], not_previous_drinks[1]))
res.append(max(eat_previous_drinks[2], not_previous_drinks[2]))
for i in range(3, n+1):
    eat_previous_drinks[i] = lst[i] + not_previous_drinks[i-2]
    not_previous_drinks[i] = lst[i] + max(eat_previous_drinks[i-1], not_previous_drinks[i-1])
    res.append(max(eat_previous_drinks[i], not_previous_drinks[i]))
    

print(max(res))