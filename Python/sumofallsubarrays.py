arr = list(map(int,input().split()))
s = []
c = 0
for i in range(len(arr)):
    c = 0
    sub = []
    for j in range(i,len(arr)):
        c = c + arr[j]
        s.append(c)
        sub.append(arr[j])
        print(sub)
maxt = 0
for i in range(len(s)):
    if maxt < s[i]:
        maxt = s[i]
print(maxt)

