N = input()
a = map(int, raw_input().split())

memo = [0 for i in range(9)]
for i in a:
	if(i < 3200):
		memo[i / 400] = memo[i / 400] + 1
	else:
		memo[8] = memo[8] + 1;

cnt = 0
for i in range(8):
	if memo[i] > 0:
		cnt = cnt + 1;
free = memo[8]

if cnt == 0:
	print 1, memo[8]
else:
	print cnt, memo[8] + cnt