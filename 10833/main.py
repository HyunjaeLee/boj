n = int(input())
ans = 0
for _ in range(n):
    student, apple = map(int, input().split())
    ans += apple % student
print(ans)
