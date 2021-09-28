import sys
from collections import defaultdict
read = sys.stdin.readline
for _ in range(int(read())):
    cnt = defaultdict(int)
    for _ in range(int(read())):
        cnt[read().split()[1]] += 1
    result = 1
    for n in cnt.values():
        result *= n+1
    print(result-1)
