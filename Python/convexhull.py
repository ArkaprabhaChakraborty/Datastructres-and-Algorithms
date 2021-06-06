from math import sqrt
import sys 

sys.setrecursionlimit(10**6) 

hullset = set()

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

def det(x1,y1,x2,y2,x3,y3):
    x = ((x2 - x1)*(y3 - y1)) - ((x3 - x1)*(y2 - y1))
    return x

def area(x1,y1,x2,y2,x3,y3):
    a = sqrt(((y2-y1)**2) + ((x2-x1)**2))
    b = sqrt(((y3-y1)**2) + ((x3-x1)**2))
    c = sqrt(((y2-y3)**2) + ((x2-x3)**2))
    s = (a+b+c)/2
    area = s*(s-a)*(s-b)*(s-c)
    if area>0:
        return sqrt(area)
    else:
        return 0


def QuickHull(x,y,px1,py1,px2,py2):
    if(len(x)<3):
        return
    Xx1 = []
    Yy1 = []
    Xx2 = []
    Yy2 = []
    global hullset
    for k in range(len(x)):
        i = x[k]
        j = y[k]
        d = det(i,j,px1,py1,px2,py2)
        if (d>0):
            Xx1.append(i)
            Yy1.append(j)
        elif(d<0):
            Xx2.append(i)
            Yy2.append(j)
    p1,q1 = Hull(Xx1,Yy1,px1,py1,px2,py2)
    p2,q2 = Hull(Xx2,Yy2,px1,py1,px2,py2)
    hullset.add((px1,py1))
    hullset.add((px2,py2))
    hullset.add((p1,q1))
    hullset.add((p2,q2))
    QuickHull(Xx1,Yy1,px1,py1,p1,q1)
    QuickHull(Xx2,Yy2,px1,py1,p2,q2)


def Hull(X,Y,px1,py1,px2,py2):
    max = 0
    p,q = 0,0
    for k in range(len(X)):
        i = X[k]
        j = Y[k]
        a = area(px1,py1,px2,py2,i,j)
        if (max<a):
            max = a
            p = i
            q = j
    return (p,q)
    #QuickHull(X,Y,px1,py1,p,q)



x = [0,1,2,4,0,1,3,3]
y = [3,1,2,4,0,2,1,3]

qsort(x,y,0,7)
print(x)
print(y)
QuickHull(x,y,x[0],y[0],x[-1],y[-1])
print(hullset)