import sys
sinput = sys.stdin.readline

num = int(sinput())
isDancing = {}

for _ in range(num):
    a, b = sinput().split()
    if a == "ChongChong" or b == "ChongChong":
        isDancing[a] = 1
        isDancing[b] = 1
    if a in isDancing or b in isDancing:
        isDancing[a] = 1
        isDancing[b] = 1
print(len(isDancing))