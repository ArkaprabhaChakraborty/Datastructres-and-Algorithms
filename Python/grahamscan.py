import sys 
from math import inf
sys.setrecursionlimit(10**6) 


def partition(x,y,l,r):
    pivot = r
    i = l-1
    while(l<r):
        if(x[l]<x[pivot]):
            i = i + 1
            temp = x[i]
            x[i] = x[l]
            x[l] = temp
            remp = y[i]
            y[i] = y[l]
            y[l] = remp
        l = l + 1
    temp = x[i+1] 
    x[i+1] = x[pivot]
    x[pivot] = temp
    temp = y[i+1] 
    y[i+1] = y[pivot]
    y[pivot] = temp
    return i+1

def qsort(x,y,l,r):
    if(l<r):
        mid = partition(x,y,l,r)
        qsort(x,y,l,mid-1)
        qsort(x,y,mid+1,r)


Hullset=set()


def slope(x1,y1,x2,y2):
    if(x2 - x1)!=0:
        s = (y2 - y1)/(x2 - x1)
    else:
        s = inf
    return s

def Hullpoint(X,Y,p,q):
    global Hullset
    min = 100000000000000000000000000000000000
    minx = miny= 0
    for k in range(len(X)):
        i = X[k]
        j = Y[k]
        s = slope(p,q,i,j)
        if(min>s):
                min = s
                minx = i
                miny = j
    return (minx,miny)

def det(x1,y1,x2,y2,x3,y3):
    x = ((x2 - x1)*(y3 - y1)) - ((x3 - x1)*(y2 - y1))
    return x

def GrahamScan_Utility(X,Y,x1,y1,x2,y2,stack):
    if (len(stack)<3):
        return
    global Hullset
    p,q = Hullpoint(X,Y,x2,y2)
    Hullset.add((p,q))    
    d = det(x1,y1,x2,y2,p,q)
    if(d>0):
        stack.append((p,q))
        GrahamScan_Utility(X,Y,x2,y2,p,q,stack)
    else:
        stack.remove((x2,y2))
        X.remove(x2)
        Y.remove(y2)
        GrahamScan_Utility(X,Y,x1,y1,p,q,stack)

def Graham_Scan(X,Y):
    global Hullset
    p = X[0]
    q = Y[0]
    Hullset.add((p,q))
    p1,q1 = Hullpoint(X,Y,p,q)
    stack = []
    stack.append((p,q))
    stack.append((p1,q1))
    GrahamScan_Utility(X,Y,p,q,p1,q1,stack)
    print(stack)
    print(Hullset)



x = [0,1,2,4,0,1,3,3]
y = [3,1,2,4,0,2,1,3]
qsort(y,x,0,len(y)-1)
Graham_Scan(x,y)



