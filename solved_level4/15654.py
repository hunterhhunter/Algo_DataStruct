n, m = map(int, input().split())
lst = list(map(int, input().split()))
lst.sort()
ss = []
def back(depth):
    if depth == m:
        print(' '.join(map(str, ss)))
        return
    
    for i in range(n):
        if lst[i] in ss:
            continue
        ss.append(lst[i])
        back(depth+1)
        ss.pop()

back(0)