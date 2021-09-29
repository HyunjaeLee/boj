N = int(input())
def prize(a, b, c):
    if a == b and b == c:
        return 10000 + a * 1000
    if a == b:
        return 1000 + a * 100
    if b == c:
        return 1000 + b * 100
    if c == a:
        return 1000 + c * 100
    return max(a, b, c) * 100
print(max(prize(*map(int, input().split())) for _ in range(N)))
