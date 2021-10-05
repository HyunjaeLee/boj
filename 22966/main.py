problem = []
for _ in range(int(input())):
    s = input().split()
    problem.append((int(s[1]), s[0]))
problem.sort()
print(problem[0][1])
