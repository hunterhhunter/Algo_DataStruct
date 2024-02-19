import sys

sinput = sys.stdin.readline

num = int(input())
cards = [i for i in range(1, num+1)]
cnt = 0

while True:
    if len(cards)-cnt == 1:
        break
    else:
        cnt += 1
        cards.append(cards[cnt])
        cnt += 1

print(cards[-1])