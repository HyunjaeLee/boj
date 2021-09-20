import sys
import math
C = int(sys.stdin.readline())
for _ in range(C):
    tok = sys.stdin.readline().split()
    S, N, T, L = tok[0], int(tok[1]), int(tok[2]), int(tok[3])
    p = False
    if S == 'O(N)' and T * N <= L * 1e8:
        p = True
    elif S == 'O(N^2)' and T * N**2 <= L * 1e8:
        p = True
    elif S == 'O(N^3)' and T * N**3 <= L * 1e8:
        p = True
    elif S == 'O(2^N)' and T * 2**N <= L * 1e8:
        p = True
    elif S == 'O(N!)' and T * math.factorial(N) <= L * 1e8:
        p = True
    if p:
        print('May Pass.')
    else:
        print('TLE!')