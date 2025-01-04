def recursion(lst: list, remain: list):
    if len(lst) == 6:
        print(*lst)
        return
    
    for i in range(len(remain)):
        lst.append(remain[i])
        recursion(lst, remain[i+1:])
        lst.pop()
# 조합문제
# 중복된 값을 set으로 검사하는게 아니라 애초에 중복되지 않도록 수를 선정
# 이 때 for에서 -5를 하는 이유는 앞에서부터 1개를 선정 후 나머지 5개를 고르는
# 경우의 수를 구하기 위해서이다.
# 1에 대한 경우의 수를 구한 후 1을 뺴줘야한다.
while True:
    inp = list(map(int, input().split()))
    
    if inp[0] == 0:
        break

    array = inp[1:]
    for i in range(inp[0]-5):
        recursion(array[i:i+1], array[i+1:])
    print()