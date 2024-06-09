import sys
sinput = sys.stdin.readline

string = sinput().rstrip()
n = int(sinput())
lst = [[0] * 26]
lst[0][ord(string[0])-97] = 1
for i in range(1, len(string)):
    lst.append(lst[i-1].copy())
    lst[i][ord(string[i])-97] += 1

for _ in range(n):
    alpha, start, end = sinput().split()
    start, end = int(start), int(end)
    if start == 0:
        print(lst[end][ord(alpha)-97])
    else:
        print(lst[end][ord(alpha)-97]-lst[start-1][ord(alpha)-97])