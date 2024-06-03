inp1 = input()
inp2 = input()

table = [[0 for _ in range(len(inp2)+1)] for _ in range(len(inp1)+1)]

for i in range(1, len(inp1)+1):
    for j in range(1, len(inp2)+1):
        if inp1[i-1] == inp2[j-1]:
            table[i][j] = table[i-1][j-1] + 1
        else:
            table[i][j] = max(table[i-1][j], table[i][j-1])

print(max(table[-1]))