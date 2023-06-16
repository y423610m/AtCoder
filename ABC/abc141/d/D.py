import heapq

N,M = map(int,input().split())
A = list(map(int,input().split()))
A = list(map(lambda x:-x,A))

heapq.heapify(A)

while(M>0 and len(A)>0):
    a = -heapq.heappop(A)
    a = a//2
    M -= 1
    if a>0:
        heapq.heappush(A, -a)
print(-sum(A))