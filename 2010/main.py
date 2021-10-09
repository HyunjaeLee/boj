import sys
input = sys.stdin.readline
n = int(input())
print(1-n+sum(int(input()) for _ in range(n)))
