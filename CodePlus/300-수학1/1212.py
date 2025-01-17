inp = input()
ans = []

for each in inp:
    n = int(each)
    for j in range(2, -1, -1):
        ans.append(str(n//2**j))
        n %= 2**j

print(int(''.join(ans)))