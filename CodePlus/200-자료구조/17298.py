n = int(input())
lst = list(map(int, input().split()))
stack = []
ans = [-1 for _ in range(n)]

# 오큰수에서 중요한 것은 스택을 사용하는 것
# 원래는 ptr 변수를 두고 탐색했지만
# 스택에 인덱스를 넣어두고 그냥 거기에 큰 값을 넣어버리면
# 포인터를 순회할 필요가 없어짐

for idx in range(n):
    while stack and lst[stack[-1]] < lst[idx]:
        ans[stack.pop()] = lst[idx]
    stack.append(idx)
    
print(*ans)