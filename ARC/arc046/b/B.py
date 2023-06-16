N = int(input())
A,B = map(int,input().split())

T = "Takahashi"
Ao = "Aoki"

if N<=A:
   print(T)
   exit()

if A == B:
   if N%(A+1)==0:
      print(Ao)
   else:
      print(T)
else:
   if(A>B):
      print(T)
   else:
      print(Ao)
