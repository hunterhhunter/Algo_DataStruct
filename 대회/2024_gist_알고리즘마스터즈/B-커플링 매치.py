import sys
sinput = sys.stdin.readline

n = int(sinput())
humans = {}
rings = {}
cnt = {}
result = []
gg = []
for _ in range(n):
    human, ring = map(str, sinput().split())
    if ring == '-':
        continue

    if ring in rings:
        cnt[ring] += 1
        if cnt[ring] > 2:
            gg.append(ring)
        rings[ring].append(human)
    else:
        rings[ring] = [human]
        cnt[ring] = 1

for i in rings.items():
    ring = i[0]
    names = i[1]
    if ring in gg:
        continue
    else:
        if cnt[ring] == 2:
            result.append(names)

print(len(result))
for i in result:
    print(*i)