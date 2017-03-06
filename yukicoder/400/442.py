def gcd(x, y):
	while y > 0:
		tmp = x;
		x = y
		y = tmp % y
  	return x

a, b = map(int, raw_input().split())
print(gcd(a + b, a * b))
