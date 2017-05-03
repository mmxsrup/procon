# -*- coding: utf-8 -*-
n = 10
dx = [1400, 1600, 1000, 2600, 2000, 1800, 3000, 1200, 2600, 1600];
dy = [1900, 2100, 1400, 3000, 2400, 2300, 3900, 1800, 3500, 2100];
sumx = 0
sumy = 0
for i in dx:
    sumx = sumx + i

for i in dy:
    sumy = sumy + i

avgx = sumx / n
avgy = sumy / n
print avgx, avgy

sx = 0
sy = 0
sxy = 0
for i in dx:
	sx = sx + pow(i - avgx, 2)
for i in dy:
	sy = sy + pow(i - avgy, 2)
for (i, j) in zip(dx, dy):
	sxy = sxy + (i - avgx) * (j - avgy)

Sx = pow(sx / (n - 1), 0.5)
Sy = pow(sy / (n - 1), 0.5)
Sxy = sxy / (n - 1)
P = Sxy / (Sx * Sy)
print Sx, Sy, P

hat_a1 = P * Sy / Sx
hat_a0 = avgy - P * Sy * avgx / Sx

print hat_a1, hat_a0

print "%f + %f x" % (hat_a0, hat_a1)

rue = 0
rsita = 0
for (x, y) in zip(dx, dy):
	rue = rue + pow(y - (hat_a0 + hat_a1 * x), 2)
for y in dy:
	rsita = rsita + pow(y - avgy, 2)
print rue, rsita
R2 = 1 - rue / rsita
print R2


#標準化しても相関係数P　はかわらないのか


