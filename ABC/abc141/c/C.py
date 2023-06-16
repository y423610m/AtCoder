N,K,Q = map(int,input().split())

score = [K-Q]*N

for _ in range(Q):
    a = int(input())
    a -= 1
    score[a] += 1

for i in range(N):
    if score[i]>0:
        print("Yes")
    else:
        print("No")