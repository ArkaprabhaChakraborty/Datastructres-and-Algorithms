arr = list(map(int,input().split()))
mx = []
m = -9999999
for i in range(len(arr)):
    if m < arr[i]:
        m = arr[i]
    mx.append(m)
print(mx)