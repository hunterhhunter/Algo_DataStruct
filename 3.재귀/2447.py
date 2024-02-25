n = int(input())
lis = [['*' for _ in range(n)] for _ in range(n)]
nsng = 0
while n != 1:
    n //= 3
    nsng += 1

def rep(lis, n):
    if n == 1:
        return [['*', '*', '*'], 
                ['*', ' ', '*'],
                ['*', '*', '*']]
    
    res = lis

    for row in range(0, 3):
        for col in range(0, 3):

    #         hang = row * 3**(n-1)
    #         hangend = (row+1) * 3**(n-1)
    #         yul = col * 3**(n-1)
    #         yulend = (col+1) * 3**(n-1)
    #         tmp = [[' ' for _ in range(yul, yulend)] for _ in range(hang, hangend)]

    #         for h in range(hang, hangend):
    #             for y in range(yul, yulend):
    #                 tmp[h-hang][y-yul] = res[h][y]

    #         go = rep(tmp, n-1)
    #         tmp2 = [[' ' for _ in range(3**n)] for _ in range(3**n)]

    #         if row == 1 and col == 1:
    #             for h in range(hang, hangend):
    #                 for y in range(yul, yulend):
    #                     res[h][y] = tmp2[h][y]
    #         else:
    #             for h in range(hang, hangend):
    #                 for y in range(yul, yulend):
    #                     res[h][y] = go[h-hang][y-yul]
    # return res

rr = rep(lis, nsng)

for i in rr:
    print(''.join(i))