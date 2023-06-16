N = int(input())
S = [input() for i in range(N)]
# print(S)

len = 6
ans = "No"

#yoko
for h in range(N):
    for w in range(N-len+1):
        cnt = 0
        for i in range(len):
            if S[h][w+i]=='#':
                cnt += 1
        if cnt+2>=len:
            ans = "Yes"
#tate
for w in range(N):
    for h in range(N-len+1):
        cnt = 0
        for i in range(len):
            if S[h+i][w]=='#':
                cnt += 1
        if cnt+2>=len:
            ans = "Yes"

#右下
for h in range(N-len+1):
    for w in range(N-len+1):
        cnt = 0
        for i in range(len):
            if S[h+i][w+i]=='#':
                cnt += 1
        if cnt+2>=len:
            ans = "Yes"
# print(S)
for h in range(N):
    S[h] = S[h][::-1]
# print(S)
    
#右下
for h in range(N-len+1):
    for w in range(N-len+1):
        cnt = 0
        for i in range(len):
            if S[h+i][w+i]=='#':
                cnt += 1
        if cnt+2>=len:
            ans = "Yes"
print(ans)