n, k = map(int, input().split())
lst = list(map(int, input().split()))
cnt = 0

# 존재하는 모든 부분집합에 대한 합을 검사하는 문제
# if 조건문에서 return을 해버리면 합이 나왔을 때 끝나므로
# 존재하는 모든 부분집합에 대해 검사할 수 없다.
def recursion(lst:list, remain: list):
    global cnt, k
    if sum(lst) == k:
        cnt += 1
    
    for i in range(len(remain)):
        lst.append(remain[i])
        recursion(lst, remain[i+1:])
        lst.pop()


for i in range(0, len(lst)):
    recursion(lst[i:i+1], lst[i+1:])
print(cnt)