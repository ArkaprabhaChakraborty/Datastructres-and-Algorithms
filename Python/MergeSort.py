# importing the sys module 
import sys 
  
# the setrecursionlimit function is 
# used to modify the default recursion 
# limit set by python. Using this,  
# we can increase the recursion limit 
# to satisfy our needs 

sys.setrecursionlimit(10**6) 


def merge(arr,p,q,r):
    # q is the middle element 
    n1 = q-p+1
    n2 = r-q
    left = []
    right = []
    i = 0
    j = 0
    # divide the array into left and right sub-parts
    for k in range(n1):
        left.append(arr[p+k])
    left.append(12345678)
    # appending a big-integer as there might be a case where there is no elements in the left
    # or the right sub-array ... so it means at that case all the elements has to be copied to the
    # given arr 
    for k in range(n2):
        right.append(arr[q+k])
    right.append(12345678)
    #compare left and right sub-array
    for k in range(p,r):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i = i + 1
        else:
            arr[k] = right[j]
            j = j + 1

def mergesort(arr,p,r):
    if(p<r):
        q = p + (r-p)//2
        mergesort(arr,p,q)
        mergesort(arr,q+1,r)
        merge(arr,p,q,r)

if __name__ == '__main__':
    print("ENTER UNSORTED ARRAY: ")
    arr = list(map(int,input().split()))
    mergesort(arr,0,(len(arr)-1))
    print("SORTED ARRAY :")
    print(arr)
