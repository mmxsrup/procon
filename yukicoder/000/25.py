n = int(raw_input())
m = int(raw_input())
tmp = m
cnt2 = 0
cnt5 = 0
while tmp % 2 == 0:
	tmp /= 2
	cnt2 += 1
while tmp % 5 == 0:
	tmp /= 5
	cnt5 += 1

if tmp != 1:
	print -1
else:
	if cnt2 > cnt5:
		n *= 5 * (cnt2 - cnt5)
		m *= 5 * (cnt2 - cnt5)
	elif cnt2 < cnt5:
		n *= 2 * (cnt5 - cnt2)
		m *= 2 * (cnt5 - cnt2)

	n *= 1000000000
	s = str(float(n) / m)

	i = -1
	while s[i] < '1' or '9' < s[i]:
		i -= 1
	print s[i]


