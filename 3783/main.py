from decimal import *
import sys
getcontext().prec = 1000
N = int(sys.stdin.readline())
for _ in range(N):
    d = Decimal(sys.stdin.readline()) 
    pow = Decimal('1') / Decimal('3')
    d = Decimal(d ** pow)
    d = round(d, 500)
    d = Decimal(d).quantize(Decimal('.0000000001'), rounding=ROUND_FLOOR)
    print(d)