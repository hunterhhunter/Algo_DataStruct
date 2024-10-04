# 아이디어
# 문자열 순회하면서 괄호 시작과 끝을 마킹
# 마킹을 튜플로 저장하고 튜플들을 순회하면서 마킹위치를 제외하고 출력
import itertools

# 모든 부분집합을 만드는 함수
def all_small_combination(arr: list):
    result = []
    for i in range(1, len(arr)+1):
        small_combinations = itertools.combinations(arr, i)
        result.extend(small_combinations)
    return result
        

inp = input()
marking = [] # 괄호의 위치를 마킹해두는 list
stack = [] # ( 이 들어가는 stack list
res = []

# 마킹부
for i in range(len(inp)):
    if inp[i] == "(":
        stack.append(i)
    elif inp[i] == ")":
        tmp = stack.pop()
        marking.append((tmp, i))

# 부분집합 만들기
comb = all_small_combination(marking)

# 출력하기
for i in comb:
    buffer = list(inp)
    for mark in i:
        buffer[mark[0]] = ""
        buffer[mark[1]] = ""
    res.append(''.join(buffer))
res = list(set(res))
res.sort()
for i in res:
    print(i)


# 콤비네이션을 만드는 방법 (비트마스킹)

