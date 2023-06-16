n = int(input())
A = list(map(int, input().split()))
A.sort()
A.reverse()

ans = 10**5
i = min(ans,n//A[0])
while i>=0:
    j = min(ans-i, (n-A[0]*i)//A[1])
    while j>=0:
        sum = i*A[0]+j*A[1]
        if (n-sum)%A[2]==0:
            cand = i+j+(n-sum)//A[2]
            if ans > cand: ans = cand
            break
        j -= 1
    i -= 1
print(ans)