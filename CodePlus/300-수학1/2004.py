a, b = map(int, input().split())

# 뒤에 0이나오는 경우는 2*5가 존재할 경우
# 따라서 2의 거듭제곱의 수와 5의 거듭제곱이 쌍을 이룰 때 0이 생성
# 둘 중 작은 거듭제곱수가 정답
def find_two(n):
    result = 0
    i = 2
    tmp = 2

    while tmp <= n:
        result += n // tmp
        tmp = 2**i
        i += 1
    return result

def find_five(n):
    result = 0
    i = 2
    tmp = 5

    while tmp <= n:
        result += n // tmp # n팩토리얼에서 5가 몇번곱해진지를 알기 위함이므로 //
        tmp = 5**i
        i += 1

    return result

# 분자 two, five에서 분모의 two, five를 빼면 정답이 나온다.
two = find_two(a) - find_two(a-b) - find_two(b)
five = find_five(a) - find_five(a-b) - find_five(b)
print(min(two, five))