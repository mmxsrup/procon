a, b = map(int, raw_input().split())
for i in range(a, b + 1):
	if i % 3 == 0 or '3' in str(i):
		print i