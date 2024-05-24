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

if kind == 14: # ㄱ자 모양일 때
    for i in range(7):
        if prev == 1 and lst[i][0] == 3:
            subspace += lst[i-1][1] * lst[i][1]
        if lst[i][0] == 3 or lst[i][0] == 4:
            height.append(lst[i][1])
        else:
            width.append(lst[i][1])
        prev = lst[i][0]

elif kind == 15: # ㄱ자 데칼코마니 모양 and ㄴ자 데칼코마니
    for i in range(7):
        if prev == 4 and lst[i][0] == 1:
            subspace += lst[i-1][1] * lst[i][1]
        if prev == 3 and lst[i][0] == 2:
            subspace += lst[i-1][1] * lst[i][1]
        if lst[i][0] == 3 or lst[i][0] == 4:
            height.append(lst[i][1])
        else:
            width.append(lst[i][1])
        prev = lst[i][0]
        
elif kind == 16: # ㄴ자 모양
    for i in range(7):
        if prev == 2 and lst[i][0] == 4:
            subspace += lst[i-1][1] * lst[i][1]
        if lst[i][0] == 3 or lst[i][0] == 4:
            height.append(lst[i][1])
        else:
            width.append(lst[i][1])
        prev = lst[i][0]

whole = max(height) * max(width) - subspace
print(n * whole)