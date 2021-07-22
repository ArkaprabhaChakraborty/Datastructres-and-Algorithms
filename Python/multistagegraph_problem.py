'''
Given a directed graph find the shortest path from a source to sink.
Here we break the graph representation into different stages.
We define a function M(i,j) = dist[j] + M(i+1,j) 
'''



def shortestDist(graph,N):
    INF = 10000000000
    dist = [0] * N
    dist[N - 1] = 0
    vert = []
    for i in range(N - 2, -1, -1):
        dist[i] = INF
        for j in range(N):
            if graph[i][j] == INF:
                continue
            dist[i] = min(dist[i],graph[i][j] + dist[j])
    return dist[0]



INF = 10000000000
graph = [[INF, 1, 2, 5, INF, INF, INF, INF],
         [INF, INF, INF, INF, 4, 11, INF, INF],
         [INF, INF, INF, INF, 9, 5, 16, INF],
         [INF, INF, INF, INF, INF, INF, 2, INF],
         [INF, INF, INF, INF, INF, INF, INF, 18],
         [INF, INF, INF, INF, INF, INF, INF, 13],
         [INF, INF, INF, INF, INF, INF, INF, 2]] 
print(shortestDist(graph,8))

