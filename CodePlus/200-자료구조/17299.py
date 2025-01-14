n = int(input())
lst = list(map(int, input().split()))
frequency = [0 for _ in range(1000001)]
stack = []
ans = [-1 for _ in range(n)]

# 오큰수와의 차이점은 frequency 배열을 한번 더 참조하느냐이다.
# 결과적으로는 O(N)인데, frequency 배열을 선언한게 주요한 듯 하다.
# 또 인덱스를 stack에 넣고 뺴는 개념을 알면 포인터를 따로 두고 순회할 필요가 없어진다.

for each in lst:
    frequency[each] += 1

for idx in range(n):
    while stack and frequency[lst[stack[-1]]] < frequency[lst[idx]]:
        ans[stack.pop()] = lst[idx]
    stack.append(idx)

print(*ans)