#peak element is the one whose left and right elements are smaller than itself
#input: [10, 20, 15, 2, 23, 90, 67] output: 20 or 90 
#as both of them have elements on left and right that are smaller than itself 
def peak(a,n):
    #if there is only one element in the array
    if n==1:
        return 0
    for i in range(n):
        if i == 1 and a[1]<a[0]:
            print(str(a[0]) + " at index "+ str(0))
        elif i == n-1 and a[n-2]<a[n-1]:
            print(str(a[n-1]) + " at index "+ str(n-1))
        elif a[i]>a[i-1] and a[i+1]<a[i]:
            print(str(a[i]) + " at index "+ str(i))

if __name__ == '__main__':
    a = list(map(int,input("Enter Array(pace separated): ").split()))
    peak(a,len(a))
