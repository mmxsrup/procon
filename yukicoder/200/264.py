a, b = raw_input().split()
a = int(a)
b = int(b)
if (a == 0 and b == 1) or (a == 1 and b == 2) or (a == 2 and b == 0):
	ans = "Won"
elif (b == 0 and a == 1) or (b == 1 and a == 2) or (b == 2 and a == 0):
	ans = 'Lost'
else:
	ans = 'Drew'
print ans