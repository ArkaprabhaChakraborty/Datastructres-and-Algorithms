'''
Given a directed graph find the shortest path from a source to sink.
Here we break the graph representation into different stages.
We define a function M(i,j) = dist[j] + M(i+1,j) 
'''

def get_min(s,n,graph,cost):
    INF = 10000000000
    min_cost = INF
    min_vert = 0
    for i in range(n):
        if (min_cost>(graph[s][i] + cost[i])):
            min_cost = (graph[s][i] + cost[i])
            min_vert = i
    return min_vert


def multistage_shortest_path_forward_approach(graph,n,stage):
    d = [0]*n
    cost = [0]*n
    for i in range(n-2,-1,-1):
        r = get_min(i,n,graph,cost)
        cost[i] = graph[i][r] + cost[r]
        d[i] = r

    p = [0]*stage
    p[stage-1] = n-1
    for i in range(1,stage-1):
        p[i] = d[p[i-1]]

    print(f"Cost is {cost[0]}")
    print("Path:")
    print_path(p)
    
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
         [INF, INF, INF, INF, INF, INF, INF, 2]]
          
multistage_shortest_path_forward_approach(graph,8,4)

