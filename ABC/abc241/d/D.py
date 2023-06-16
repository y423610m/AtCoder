import heapq
#heapq.heapify(A)
#heapq.heappop()
#heapq.heappush()

Q=int(input())
A = []
B = []

for _ in range(Q):
    query = list(map(int,input().split()))
    if query[0] == 1:
        x = query[1]
        heapq.heappush(A)