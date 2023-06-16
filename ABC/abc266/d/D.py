N = int(input())

TMAX = 100000
Snukes = [[0]*2 for i in range(TMAX+1)]
for i in range(N):
    t,x,a = map(int, input().split())
    Snukes[t][0] = x
    Snukes[t][1] = a

LINF = 1e18
dp = [[-LINF]*5 for i in range(TMAX+1)]
dp[0][0] = 0
for t in range(TMAX):
    for x in range(5):
        for dx in range(-1,1+1):
            if 0<=x+dx and x+dx<=4:
                dp[t+1][x] = max(dp[t+1][x], dp[t][x+dx])

    Snuke = Snukes[t+1]
    if dp[t+1][Snuke[0]]!=-LINF:
        dp[t+1][Snuke[0]] += Snuke[1]

ans = 0
for i in range(5):
    ans = max(ans, dp[TMAX][i])

print(ans)