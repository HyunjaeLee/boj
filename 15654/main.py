from itertools import permutations
import sys
read = sys.stdin.readline
_, M = map(int, read().split())
for seq in permutations(sorted(map(int, read().split())), M):
    print(' '.join(map(str, seq)))
