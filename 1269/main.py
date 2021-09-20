import sys
sys.stdin.readline()
A = set(map(int, sys.stdin.readline().split()))
B = set(map(int, sys.stdin.readline().split()))
print(len(A ^ B))