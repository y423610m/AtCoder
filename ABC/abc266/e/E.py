N = int(input())
NMAX = 100000

dp = [0.0]*NMAX
dp[0] = 3.5


for i in range(1,NMAX):
    for x in range(1,6+1):
        dp[i] += max(dp[i-1], x)
    dp[i] /= 6
print(dp[N-1])