import sys
sinput = sys.stdin.readline

words = dict()
a, b = map(int, sinput().split())

for _ in range(a):
    inp = sinput().rstrip()
    if len(inp) >= b:
        if inp in words:
            words[inp] += 1
        else:
            words[inp] = 1

lis = list(words.items())

lis.sort(key=lambda x: (-x[1], -len(x[0]), x[0]))

for i in lis:
    print(i[0])