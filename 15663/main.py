from itertools import permutations
_, M = map(int, input().split())
s = set()
for seq in permutations(sorted(map(int, input().split())), M):
    if seq in s:
        continue
    s.add(seq)
    print(' '.join(map(str, seq)))
