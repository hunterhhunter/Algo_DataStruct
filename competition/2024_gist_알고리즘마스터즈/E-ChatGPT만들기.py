import sys
sinput = sys.stdin.readline

n, k, m = map(int, sinput().split())
dic = {}
sentence = []
for _ in range(n):
    senten = sinput().rstrip()
    for i in range(len(senten)):
        if dic.items() != []:
            if senten[i] in dic[i]:
                dic[i][senten[i]] += 1
            else:
                dic[i][senten[i]] = 1
        else:
            dic[i] = {}