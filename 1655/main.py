import heapq, sys
read = sys.stdin.readline
N = int(read())
left = []
right = []
for i in range(N):
    x = int(read())
    if i&1:
        if -left[0] > x:
            heapq.heappush(right, -heapq.heappop(left))
            heapq.heappush(left, -x)
        else:
            heapq.heappush(right, x)
    else:
        if right and right[0] < x:
            heapq.heappush(left, -heapq.heappop(right))
            heapq.heappush(right, x)
        else:
            heapq.heappush(left, -x)
    print(-left[0])
