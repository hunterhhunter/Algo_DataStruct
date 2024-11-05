n = int(input())
inp = list(input())
res = 0

for _ in range(n-1):
    cpr = inp.copy()
    fix = 0
    xx = input()
    
    for i in xx:
        if i in cpr:
            cpr.remove(i)
        else:
            fix += 1
        
    if len(cpr) < 2 and fix < 2:
        res += 1
print(res)