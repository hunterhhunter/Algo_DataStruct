import sys
lst = [True for _ in range(1000001)]

for i in range(2, len(lst)):
    if not lst[i]:
        continue
    for j in range(2*i, len(lst), i):
        lst[j] = False

while True:
    inp = int(sys.stdin.readline())
    if inp == 0:
        break
    for i in range(3, inp//2+1, 2): # 나누기 2가 최적
        if lst[i] and lst[inp-i]:
            print(f'{inp} = {i} + {inp-i}')
            break
    else:
        print("Goldbach's conjecture is wrong.")

# 테스트케이스의 개수만큼 푸는 것도 고려해보는게 좋다.