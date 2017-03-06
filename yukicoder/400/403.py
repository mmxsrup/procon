a, b, c = map(int, raw_input().split('^'))
mod = 10**9 + 7
if a % mod == 0:
	x = 0
	y = 0
else:
	x = pow(pow(a, b, mod), c, mod)
	y = pow(a, pow(b, c, mod - 1), mod)
print x, y