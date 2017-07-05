mod1 = 1000000000
mod2 = 1000000007
s = raw_input()

size = len(s)
ans = ""
for i in range (0, size / 2 + 1):
	print "i", i
	if s[i] < s[size - i - 1]:
		ans = ans * (s[i] - '0')
	else:
		ans = ans * (s[i] - '0')
	
print ans % mod1
print ans % mod2
