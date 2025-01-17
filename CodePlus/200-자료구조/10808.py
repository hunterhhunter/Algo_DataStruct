inp = input()
lst = [0 for _ in range(26)]

for each in inp:
    lst[ord(each)-97] += 1

print(*lst)