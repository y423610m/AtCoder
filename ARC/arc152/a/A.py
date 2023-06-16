N,L = map(int,input().split())
A = list(map(int,input().split()))

sum = 0
ans = "Yes"
for i in range(N):
    if sum + (i+1)*(A[i]-1)>=L:
        ans = "No"
    sum += A[i]

print(ans)
