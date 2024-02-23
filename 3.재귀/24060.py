def merge_sort(arr):
    if len(arr) < 2:
        return arr
    # global cnt, cnt2, cnt3
    # cnt += 1

    # print(f'---------------{cnt} 회차 분할---------------')
    # print(arr)

    """len(arr)+1을 해주는 이유는 의사코드에서 A[p..q]와 A[q+1..r]을 병합한다고 함
    => 4, 5, 1, 3, 2 -> [4, 5, 1], [3, 2]"""
    mid = (len(arr)+1) // 2
    low_arr = merge_sort(arr[:mid])
    high_arr = merge_sort(arr[mid:])
    # cnt3 += 1
    # print(f'---------------{cnt3} 회차 병합 할 배열---------------')
    # print(f'low_arr: {low_arr}     high_arr: {high_arr}')

    l = h = 0
    merged_arr = []

    # cnt2 += 1

    while l < len(low_arr) and h < len(high_arr):
        if low_arr[l] < high_arr[h]:
            merged_arr.append(low_arr[l])
            ans.append(low_arr[l])
            l += 1
        else:
            merged_arr.append(high_arr[h])
            ans.append(high_arr[h])
            h += 1

    while l < len(low_arr):
        merged_arr.append(low_arr[l])
        ans.append(low_arr[l])
        l += 1            

    while h < len(high_arr):
        merged_arr.append(high_arr[h])
        ans.append(high_arr[h])
        h += 1

    # print(f'-----------{cnt2} 회차 병합-----------------')    
    # print(merged_arr)
    return merged_arr

ans = []
# cnt = cnt2 = cnt3 = 0
size, c = map(int, input().split())
arr = list(map(int, input().split()))
merge_sort(arr)

if len(ans) >= c:
    print(ans[c-1])
else:
    print(-1)