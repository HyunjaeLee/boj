import math
N = int(input())
nums = [int(input()) for _ in range(N)]
nums.sort()
diff = [nums[i+1]-nums[i] for i in range(N-1)]
div = math.gcd(*diff)
result = [div]
for a in range(2, int(math.sqrt(div))+1):
    if div%a == 0:
        result.append(a)
        if a != div//a:
            result.append(div//a)
print(' '.join(map(str, sorted(result))))
