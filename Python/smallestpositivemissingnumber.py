x = list(map(int,input().split()))
for i in range(len(x)):
    correctpos = x[i]-1
    while 1 <= x[i] <= len(x) and x[i] != x[correctpos]:
        x[i],x[correctpos] = x[correctpos],x[i]
        correctpos = x[i] - 1

for i in range(len(x)):
    if x[i] != i+1:
        print(i+1)
        break
print(i+1)
