import sys
sinput = sys.stdin.readline

num = int(sinput())
lis = []
dic = {}
for _ in range(num):
    nn = int(sinput())
    lis.append(nn)
lis.sort()

print(round(sum(lis)/len(lis)))
print(lis[len(lis)//2])

for i in lis:
    if i in dic:
        dic[i] += 1
    else:
        dic[i] = 1
mx = max(dic.values())
mx_dic = []
for i in dic.keys():
    if mx == dic[i]:
        mx_dic.append(i)

if len(mx_dic) > 1:
    print(mx_dic[1])
else:
    print(mx_dic[0])

print(lis[-1] - lis[0])