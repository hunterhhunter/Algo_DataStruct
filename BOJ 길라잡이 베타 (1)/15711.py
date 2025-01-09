import sys
input = sys.stdin.readline

# 1. 골드바흐의 추측은 400경까지는 성립한다고 증명됨.
#       => 따라서 4 X 10^12 이하의 모든 짝수는 YES
# 2. 홀수만 소수의 합으로 추측할 수 있는지를 보면 되는데
#    두 수의 합이 홀수인 경우는 짝수 + 홀수
#    소수 중 짝수인 소수는 2뿐이다.
#       => 따라서 홀수-2가 소수인지만 판별하는 되는 문제이다.

# 결론적으로 짝수인 경우 가능, 홀수인 경우 홀수-2가 소수인지 판별
# 계산량은 최대수인 (4 X 10^12)**0.5 인 2 X 10^6이하의 소수를 모두 구한 후
# 그거로 다 나눠보면 소수인지 판별이 가능하다.

prime = []
isprime = [True for _ in range(2000001)]
isprime[0], isprime[1] = False, False

for i in range(2, 2000001):
    if not isprime[i]:
        continue
    for j in range(i*i, 2000001, i):
        isprime[j] = False

for i in range(2, 2000001):
    if isprime[i]:
        prime.append(i)

n = int(input())

for _ in range(n):
    a, b = map(int, input().split())
    sm = a + b
    sm2 = sm-2

    if sm == 2:
        print("NO")
        continue
    elif sm % 2 == 0:
        print("YES")
        continue
    else:
        if sm > 2000001:
            for each in prime:
                if sm2 % each == 0:
                    print("NO")
                    break
            else:
                print("YES")
                continue
        else:
            if isprime[sm2]:
                print("YES")
                continue
            else:
                print("NO")
                continue