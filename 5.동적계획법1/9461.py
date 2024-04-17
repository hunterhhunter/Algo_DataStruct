n = [0 for _ in range(101)]
lst = [0, 1, 1, 1, 2]
a = int(input())

for i in range(5):
    n[i] = lst[i]

for j in range(5, 101):
    n[j] = n[j-1] + n[j-5]

for _ in range(a):
    inp = int(input())
    print(n[inp])

