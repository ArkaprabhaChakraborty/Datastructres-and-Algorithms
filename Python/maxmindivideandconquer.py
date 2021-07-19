'''
Finding Maximum and Minimum in an array using divide and conquer approach
'''

def maxmin(i,j,arr,max,min):
    if(i==j):
        max = arr[0]
        min = arr[0]
    elif(i==j-1):
        if (arr[i]>arr[j]):
            max = arr[i]
            min = arr[j]
        else:
            max = arr[j]
            min = arr[i]
    else:
        mid = (i + j)//2
        a , b = maxmin(i,mid,arr,max,min)
        a1, b1 = maxmin(mid+1,j,arr,max,min)
        if(a > a1):
            max = a
        else:
            max = a1
        
        if(b>b1):
            min = b1
        else:
            min = b
    return max,min

arr = [22,13,-5,-8,15,60,17,31,47]
print(maxmin(0,len(arr)-1,arr,0,0))