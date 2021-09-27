import itertools
_, M = map(int, input().split())
s = set(map(int, input().split()))
for seq in itertools.combinations_with_replacement(sorted(s), M):
    print(' '.join(map(str, seq)))
