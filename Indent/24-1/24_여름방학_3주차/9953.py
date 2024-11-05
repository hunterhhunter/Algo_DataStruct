inp = input()
c4 = input()

ans = []
idx = 0 # 인덱스 지시자

for i in inp:
    ans.append(i)
    idx += 1
    # 인덱스 음수 처리
    new_idx = max(idx-len(c4), 0)
    # 사실..!
    # new_idx 자리에 (idx-len(c4)) 넣어도 
    # 음수 인덱싱으로 큰 차이가 없음.
    if ''.join(ans[new_idx:idx]) == c4:
        # 제거 로직
        for _ in range(len(c4)):
            ans.pop()
            idx -= 1
if ans:
    print(''.join(ans))
else:
    print('FRULA')

# 복잡도 n(폭발 문자열의 길이가 아무리 길어도..?)