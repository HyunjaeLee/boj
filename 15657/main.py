from itertools import combinations_with_replacement as cwr
import sys
read = sys.stdin.readline
_, M = map(int, read().split())
for seq in cwr(sorted(map(int, read().split())), M):
    print(' '.join(map(str, seq)))
