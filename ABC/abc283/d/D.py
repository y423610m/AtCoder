from collections import defaultdict
S=input()

T = []
# used = defaultdict(int)
used = {}
ans = "Yes"
for s in S:
    if s=='(':
        T.append('(')
    elif s==')':
        while T[-1]!='(':
            t = T[-1]
            used[t] = False
            T.pop()
        T.pop()

    else:
        if used[s]:
            ans = "No"
        used[s] = True
        T.append(s)
print(ans)