small, big = map(int, input().split())

tmp = big - small + 1


print(big-small-(int(big**0.5) - int(small**0.5)) +1)