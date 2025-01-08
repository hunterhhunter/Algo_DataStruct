n = int(input())
prime_number = []
ans = 0
primes = [True for _ in range(n+1)]
primes[0], primes[1] = False, False

# 에라토스테네스의 체
for i in range(2, int(n**0.5)+1):
    if not primes[i]:
        continue
    for j in range(i*i, n+1, i):
        primes[j] = False

for i in range(n+1):
    if primes[i]:
        prime_number.append(i)

# 누적합?은 아닌듯! n이 커지면 결국 n^2이라 안됨.
# for i in range(len(sum_of_prime)-1, -1, -1):
#     for j in range(i-1, -1, -1):
#         if sum_of_prime[i]-sum_of_prime[j] == n:
#             ans += 1

# 투포인터로 선언
# 투포인터에서 중요한 것은 시작점을 옮기는 조건을 잘 설정하는 것이다.
# 이 문제에서는 시작에서 끝까지의 합이 n보다 크면 시작+1을 해서 옮기고
# n보다 작다면 끝+1을 해서 옮겨가며 합이 목표한 수와 같은지를 찾는 것이다.
# 이렇게 되면 매 루프마다 두 포인터 중 하나는 1씩 증가
# 배열의 마지막에 닿는데까지 O(N)이라고 할 수 있다.
# O(N^2)이 아닌 이유는 시작(i)과 끝(end) 포인터는 따로 N번 증가하기 때문에 2N이라고 할 수 있다.
# 상수 떼고 O(N)이다.
temp_sum = 0
end = 0

for i in range(len(prime_number)):
    while temp_sum < n and end < len(prime_number):
        temp_sum += prime_number[end]
        end += 1
    if temp_sum == n:
        ans += 1
    temp_sum -= prime_number[i]

print(ans)