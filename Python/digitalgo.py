'''

'''

n,q = map(int,input().split())
arr = list(map(int,input().split()))
flag = False
flag_value = -1
for i in range(q):
    index = (int(input()))
    c = arr[index - 1]
    comp = 0
    while(c):
        r = c % 10
        comp = comp + r
        c = c//10
    for j in range(index-1,len(arr)):  
        d = arr[j]
        ds = 0
        while(d):
            r = d % 10
            ds = ds + r
            d = d//10
        if ds < comp and arr[index-1]<arr[j]:
            flag_value = j+1
            break
        else:
            flag_value = -1 
    print(flag_value) 
