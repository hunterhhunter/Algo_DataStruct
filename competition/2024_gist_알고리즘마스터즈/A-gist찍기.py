import sys
sinput = sys.stdin.readline

n = int(sinput())

for _ in range(n):
    print('G'*n+'.'*3*n)
for _ in range(n):
    print('.'*n+'I'*n+'.'*n+'T'*n)
for _ in range(n):
    print('.'*2*n+'S'*n+'.'*n)