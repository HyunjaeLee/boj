import re
s = 'love' if re.match('.*U.*C.*P.*C.*', input()) else 'hate'
print(f'I {s} UCPC')
