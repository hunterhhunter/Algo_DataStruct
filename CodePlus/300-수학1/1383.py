inp = input()
ans = ""
inp = inp[::-1]

for _ in range((3-len(inp)%3)%3):
    inp += "0"

for i in range(0, len(inp), 3):
    an = 0
    tmp = inp[i:i+3]
    for j in range(0, 3):
        an += int(tmp[j]) * 2**j
    ans += str(an)

print(ans[::-1])