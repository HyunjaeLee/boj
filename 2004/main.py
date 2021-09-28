n, m = map(int, input().split())
def count(a, b):
    result = 0
    while a > 0:
        a //= b
        result += a
    return result
cnt2 = count(n, 2) - count(m, 2) - count(n-m, 2)
cnt5 = count(n, 5) - count(m, 5) - count(n-m, 5)
print(min(cnt2, cnt5))
