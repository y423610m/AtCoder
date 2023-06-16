N = int(input())

memo = [True]*(N+1)
memo[0]=False
memo[1]=False
for i in range(2,N+1):
    if memo[i]:
        print(i,end=" ")
        for j in range(2*i,N+1,i):
            memo[j]=False
print("")