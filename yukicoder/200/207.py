a, b = map(int, raw_input().split())
for i in range(a, b + 1):
	if i % 3 == 0:
		print i
		continue
	ok = False
	tmp = i
	while tmp > 0:
		if tmp % 10 == 3:
			ok = True
			break
		tmp /= 10
	if ok:
		print i