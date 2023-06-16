N=int(input())
A=list(map(int,input().split()))
A.sort()

cnt = [0]*(A[-1]+1)
for a in A:
    cnt[a] += 1

ans = 0
for j in range(N):
    if j>0 and A[j]==A[j-1]: continue
    for k in range(j,N):
        if k>0 and A[k]==A[k-1]: continue
        if A[j]*A[k]>A[-1]:
            break
        else:
            if A[j]!=A[k]:
                ans+=cnt[A[j]]*cnt[A[k]]*cnt[A[j]*A[k]]*2
            else:
                ans+=cnt[A[j]]*cnt[A[k]]*cnt[A[j]*A[k]]
            
print(ans)