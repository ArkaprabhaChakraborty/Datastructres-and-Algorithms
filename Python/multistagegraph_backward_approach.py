'''
Given a directed graph find the shortest path from a source to sink.
Here we break the graph representation into different stages.
We define a function M(i,j) = dist[j] + M(i+1,j) 
'''




def multistage_shortest_path_backward_approach(graph,n,stage):
    d = [0]*n
    cost = [0]*n
    for i in range(1,n):
        for j in range(None):
        r = None #insert 
        cost[i] = graph[i][r] + cost[r]
        d[i] = r

    p = [0]*stage
    p[stage-1] = n-1
    for i in range(stage-2,0,-1):
        p[i] = d[p[i+1]]

    print(f"Cost is {cost[n-1]}")
    print("Path:")
    print_path(p)
    print(cost)
    print(d)    

def print_path(path):
    print(path[0],end=" ")
    for i in path[1:len(path)]:
        print(f"-> {i}",end=" ")
    print()



INF = 10000000000
graph = [[INF,  1,   2,  5,   INF, INF, INF, INF],
         [INF, INF, INF, INF,  4,  11, INF, INF],
         [INF, INF, INF, INF, 9,    5,   16, INF],
         [INF, INF, INF, INF, INF, INF,   2, INF],
         [INF, INF, INF, INF, INF, INF, INF, 18],
         [INF, INF, INF, INF, INF, INF, INF, 13],
         [INF, INF, INF, INF, INF, INF, INF, 2],
         [INF, INF, INF, INF, INF, INF, INF, INF],]
          
multistage_shortest_path_backward_approach(graph,8,4)

