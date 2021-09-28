import sys
s1 = ' ' + sys.stdin.readline().rstrip()
s2 = ' ' + sys.stdin.readline().rstrip()
dp = [[0]*len(s2) for _ in range(len(s1))]
result = 0
for i in range(1, len(s1)):
    for j in range(1, len(s2)):
        if s1[i] == s2[j]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        result = max(result, dp[i][j])
print(result)
