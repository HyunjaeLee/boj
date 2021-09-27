import heapq, sys
read = sys.stdin.readline
T = int(read())
for _ in range(T):
    read()
    h = list(map(int, read().split()))
    heapq.heapify(h)
    ans = 1
    while len(h) > 1:
        a = heapq.heappop(h)
        b = heapq.heappop(h)
        pro = a * b
        ans = ans*pro % 1_000_000_007
        heapq.heappush(h, pro)
    print(ans)
