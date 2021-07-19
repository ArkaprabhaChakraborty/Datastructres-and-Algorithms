"""
The greedy container loading problem

Let Wi be the weights of containers and C be the capacity.
For a given capacity, we want the maximum number of containers
"""


def containers(Weights,c):
    W = sorted(Weights)
    X = [0]*len(W)
    count = 0
    i= 0
    while(i<len(W) and count < c):
        count = count + W[i]
        X[i] = 1
        i = i + 1
    for i in range(len(X)):
        if(X[i] == 1):
            print(f"{W[i]}, ",end = "")


W = [100,200,50,90,150,50,20,80]
c = 400
containers(W,c)            