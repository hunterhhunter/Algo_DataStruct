import sys
sinput = sys.stdin.readline

n = int(sinput())
rgb = []
sum = 0
idx = 0

for _ in range(n):
    rgb.append(list(map(int, sinput().split())))

red = rgb[0][0] + min(rgb[1][1], rgb[1][2])
green = rgb[0][1] + min(rgb[1][0], rgb[1][2])
blue = rgb[0][2] + min(rgb[1][0], rgb[1][1])

lst = [red, green, blue]
idx = lst.index(min(lst))
sum += rgb[0][idx]

for i in range(1, n-1):
    tmplst = []
    for z in range(3):
        if z == idx:
            tmplst.append(10000)
        else:
            tmplst.append(rgb[i][z])
    
    red = tmplst[0] + min(rgb[i+1][1], rgb[i+1][2])
    green = tmplst[1] + min(rgb[i+1][0], rgb[i+1][2])
    blue = tmplst[2] + min(rgb[i+1][0], rgb[i+1][1])

    lst = [red, green, blue]
    idx = lst.index(min(lst))
    sum += rgb[i][idx]

tmplst = []
for z in range(3):
    if z == idx:
        tmplst.append(10000)
    else:
        tmplst.append(rgb[-1][z])
sum += min(tmplst)

print(sum)