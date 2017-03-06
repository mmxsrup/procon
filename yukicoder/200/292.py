s, t, u = raw_input().split()
t = int(t)
u = int(u)
ans = ""
for i in range(len(s)):
	if i == t: continue
	if i == u: continue
	ans += s[i]
print ans
