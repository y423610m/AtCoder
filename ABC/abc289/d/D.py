N = int(input())
A = list(map(int,input().split()))
M = int(input())
B = set(map(int,input().split()))
X = int(input())

dp = [0]*(X+1)
dp[0] = 1
for a in A:
    for i in range(X+1):
        if i-a in B:
            continue
        if i - a >= 0:
            dp[i] |= dp[i-a]
#print(dp[:10])
if dp[X] == 1:
    print("Yes")
else:
    print("No")
