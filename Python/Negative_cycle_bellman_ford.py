'''
Bellman and Ford algorithm for shortest path using dynamic programming.
'''

INF = 10000000000000000000000000

def Bellman_Ford_Calculate(W_edgelist,n,v):
    d = [INF] * n
    d[v]=  0
    p = [-1]*n
    for i in range(n-1):
        for j in range(len(W_edgelist)):
            x,y,w  = W_edgelist[j]
            if(d[x]<INF):
                if(d[y] > (d[x]+ w)):
                    d[y] = d[x] + w
                    p[y] = x    
    return d,p


def Bellman_Ford(graph,n,v):
    d,p = Bellman_Ford_Calculate(graph,n,v)
    while(True):
        t = input("(Enter 'exit' to exit) Enter terminal vertex: ")
        if t == "exit":
            break
        if(int(t)<n):
            t = int(t)
            if(d[t]==INF):
                print("No path exists")
            else:
                path = []
                curr = t
                while(curr!=-1):
                    path.append(curr)
                    curr = p[curr]
                print(f"path from {v} to {t} is:")
                for i in path[::-1]:
                    print(i,end=" ")
                print()
                print(f"Cost: {d[t]}")

def negative_cycle(graph,n,v):
    d,p = Bellman_Ford_Calculate(graph,n,v)
    c = -1
    for i in range(len(graph)):
        x,y,w = graph[i]
        if(d[x]<INF):
            if(d[y] > (d[x]+ w)):
                c = y
    if c !=-1:
        for i in range(n):
            c = p[c]
        cycle = []
        v = c
        while (True):
            cycle.append(v)
            if (v == c and len(cycle) > 1):
                break
            v = p[v]
        cycle.reverse()
        # Printing the negative cycle
        for v in cycle:      
            print(v, end = " ")            
        print()  
    else:
        print(-1)
         
          


graph = [[0, 1, 1],
        [1, 2, 2],
        [2, 3, 3],
        [3, 4, -3],
        [4, 1, -3]]
n =  5
v = 0

negative_cycle(graph,n,1)
