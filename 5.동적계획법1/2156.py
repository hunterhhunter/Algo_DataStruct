import sys
sinput = sys.stdin.readline

n = int(sinput())
lst = [0]
eatFirst, eatSecond = [], []
eat_upper, eat_lower = [], []
for _ in range(n):
    lst.append(int(sinput()))

eat_upper.append([0, 0])
eat_upper.append([lst[1], 0])
eat_lower.append([0, 0])
eat_lower.append([lst[1], 0])

for i in range(2, n):
    eatFupper = lst[i] + eat_lower[i-1][0] # 처음 & 전의 것 먹기
    eatFlower = lst[i] + eat_upper[i-2][0] # 처음 & 전의 것 안 먹기

    eatSupper = lst[i] + eat_lower[i-1][1] # 두번째부터 & 전의 것 먹기
    eatSlower = lst[i] + eat_upper[i-2][1] # 두번째부터 & 전의 것 안 먹기
    
    eat_upper.append([eatFupper, eatSupper])
    eat_lower.append([eatFlower, eatSlower])
    eatFirst.append(max(eatFupper, eatFlower))
    eatSecond.append(max(eatSupper, eatSlower))

print(max(max(eatFirst, eatSecond)))