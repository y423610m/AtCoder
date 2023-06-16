S = input()

cnt = [0]*10
for s in S:
    cnt[int(s)] += 1

for i in range(8,1000,8):
    T = str(i)
    if len(T)<3 and len(T)<len(S): continue
    c = [0]*10
    for t in T:
        c[int(t)] += 1
    ok = True
    for j in range(10):
        if cnt[j] < c[j]: ok = False
    if ok:
        print("Yes")
        exit()
print("No")