import math 
t = int(input())
for _ in range(t):
    n = int(input())
    maxit = 0
    for __ in range(n):
        s,p,v = map(int,input().split()) 
        profit = v * math.floor((p/(s+1)))
        maxit = max(maxit,profit)
    print(maxit)
 