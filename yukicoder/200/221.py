n = input()
zen = 10000 - n
aku = n
zen_taiho = zen / 100.0
aku_taiho = aku * 99.0 / 100.0
ans = zen_taiho / (aku_taiho + zen_taiho) * 100.0
print ans