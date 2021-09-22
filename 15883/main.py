import itertools
for L, I, S, T, F, O in itertools.permutations(range(0, 16), 6):
    if L == 0 or F == 0 or S == 0:
        continue
    LIST = (L<<12) + (I<<8) + (S<<4) + T
    FILO = (F<<12) + (I<<8) + (L<<4) + O
    STACK = LIST + FILO
    if ((STACK>>16) & 0xF) != S:
        continue
    if ((STACK>>12) & 0xF) != T:
        continue
    def duplicate(x):
        return x == L or x == I or x == S or x == T or x == F or x == O
    A, C, K = ((STACK>>8) & 0xF), ((STACK>>4) & 0xF), (STACK & 0xF)
    if duplicate(A) or duplicate(C) or duplicate(K):
        continue
    if A == C or C == K or K == A:
        continue
    print('{:04x} + {:04x} = {:05x}'.format(LIST, FILO, STACK))
