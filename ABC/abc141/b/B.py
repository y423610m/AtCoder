S = input()
N = len(S)

ans = "Yes"
for i in range(N):
    if i%2==0 and S[i]=='L':
        ans = "No"
    if i%2==1 and S[i]=='R':
        ans = "No"
print(ans)
