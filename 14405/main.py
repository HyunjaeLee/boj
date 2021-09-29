import re
p = re.compile('(pi|ka|chu)+$')
print('YES' if p.match(input()) else 'NO')
