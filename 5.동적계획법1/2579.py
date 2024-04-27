import sys
sinput = sys.stdin.readline

n = int(sinput())
lst = [0]
lower, upper = [0], [0] # lower는 전의 것을 밟지 않은 경우 upper는 전의 것을 밟은 경우

for _ in range(n):
    lst.append(int(sinput()))

tmplst = [0 for _ in range(len(lst))]
tmplst[1]= lst[1]
lower.append(lst[1])
upper.append(lst[1])
for i in range(2, n+1):
    low = lst[i] + tmplst[i-2]
    up = lst[i] + lower[i-1]
    lower.append(low)
    upper.append(up)
    tmplst[i] = max(lower[i], upper[i])

print(tmplst[-1])