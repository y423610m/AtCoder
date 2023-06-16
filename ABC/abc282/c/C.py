N = int(input())
S = input()

cnt = 0
ans = ""
for i in range(N):
    if S[i] == '"':
        cnt = 1 - cnt
        print(S[i], end="")
    elif S[i]==",":
        if cnt ==0:
            print(".",end="")
        else:
            print(",",end="")
    else:
        print(S[i],end="")
print("")
