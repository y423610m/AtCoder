N=int(input())
A=list(map(int,input().split()))
M = max(A)
m = min(A)
cnt = [0]*(M+1)
for a in A: cnt[a] += 1
sq = int(M**0.5)+1
ans = 0
for i in range(m,sq):
    if cnt[i]==0: continue
    ans += cnt[i*i]*cnt[i]*cnt[i]
    for j in range(i+1,M+1):
        if i*j>M: break
        ans += cnt[i*j]*cnt[i]*cnt[j]*2

print(ans)


