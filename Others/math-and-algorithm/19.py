n = int(input())
A = list(map(int,input().split()))

cnt = [0]*3

for a in A:
    cnt[a-1] += 1

print( cnt[0]*(cnt[0]-1)//2 + cnt[1]*(cnt[1]-1)//2 + cnt[2]*(cnt[2]-1)//2 )