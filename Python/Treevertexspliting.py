import sys 
  
# the setrecursionlimit function is 
# used to modify the default recursion 
# limit set by python. Using this,  
# we can increase the recursion limit 
# to satisfy our needs 
  
sys.setrecursionlimit(10**6) 

"""
The Binary Tree Vertex splitting problem
"""

def TVS(T,delta,d,Tree,weight,root,N):
    if(Tree[T]!=0):
        if(2*T>N):
            d[T] = 0
        else:
            TVS(2*T,delta,d,Tree,weight,root,N)
            d[T] = max(d[T],d[2*T]+weight[2*T])
            if((2*T + 1)<= N):
                TVS((2*T+1),delta,d,Tree,weight,root,N)
                d[T] = max(d[T],d[2*T+1] + weight[2*T + 1])
        if(Tree[T]!=root) and (d[T] + weight[T] > delta):
            print(Tree[T])
            d[T] = 0
            


root = 0
delta = 3
Tree = [0,1,2,3,0,4,5,6,0,0,7,8,0,0,9,10]
weights = [0,0,4,2,0,2,1,3,0,0,1,4,0,0,2,3]
d = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

TVS(1,delta,d,Tree,weights,1,len(Tree)-1)

