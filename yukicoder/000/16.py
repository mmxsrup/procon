x, n = map(int, raw_input().split())
a = map(int, raw_input().split())

mod = 1000003
ans = 0
for i in a:
	ans += pow(x, i, mod)
print ans % mod