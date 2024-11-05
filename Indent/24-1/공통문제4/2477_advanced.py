n = int(input())

lst = []
kind = 0
prev = 0
whole = 0
subspace = 0
width, height = [], []

for _ in range(6):
    ls = list(map(int, input().split()))
    kind += ls[0]
    lst.append(ls)

lst.append(lst[0])

for i in range(7):
    if prev == 1 and lst[i][0] == 3: # ㄱ 모양
        subspace += lst[i-1][1] * lst[i][1]
    if prev == 4 and lst[i][0] == 1: # ㄱ의 데칼코마니
            subspace += lst[i-1][1] * lst[i][1]
    if prev == 3 and lst[i][0] == 2: # ㄴ의 데칼코마니
        subspace += lst[i-1][1] * lst[i][1]
    if prev == 2 and lst[i][0] == 4: # ㄴ모양
        subspace += lst[i-1][1] * lst[i][1]
    if lst[i][0] == 3 or lst[i][0] == 4:
        height.append(lst[i][1])
    else:
        width.append(lst[i][1])
    prev = lst[i][0]


whole = max(height) * max(width) - subspace
print(n * whole)