import sys
readln = sys.stdin.readline
N = int(readln())
meet = [tuple(map(int, readln().split())) for _ in range(N)]
meet.sort(key=lambda x: (x[1], x[0]))
end = 0
cnt = 0
for pair in meet:
    if pair[0] < end:
        continue
    cnt += 1
    end = pair[1]
print(cnt)
