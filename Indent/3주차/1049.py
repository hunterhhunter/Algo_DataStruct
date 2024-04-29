import sys
sinput = sys.stdin.readline

n, m = list(map(int, sinput().split()))
package = []
each = []
for _ in range(m):
    package_price, each_price = map(int, sinput().split())
    package.append(package_price)
    each.append(each_price)

package_min = min(package)
each_min = min(each)

print(min(package_min*(n//6+1), each_min*n, package_min*(n//6)+each_min*(n%6)))
# 패키지만 사는게 싼 경우, 낱개만 사는게 싼 경우, 패키지 + 낱개인 경우