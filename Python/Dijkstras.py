class Graph:
    def __init__(self,v):
        self.vertices = v
        self.graph = [[0 for i in range(v)] for i in range(v)]
        self.parent = [-1 for i in range(v)]

    def add_weighted_undirected_edge(self,u,v,w):
        self.graph[u][v] = w
        self.graph[v][u] = w
    
    def minDistance(self,dist,queue):
        minimum = float("Inf")
        min_index = -1
        for i in range(len(dist)):
            if dist[i] < minimum and i in queue:
                minimum = dist[i]
                min_index = i
        return min_index

    def dijkstra(self, src):
        row = len(self.graph)
        col = len(self.graph[0])
        dist = [float("Inf")] * row
        dist[src] = 0
     
        # Add all vertices in queue
        queue = []
        for i in range(row):
            queue.append(i)
             
        #Find shortest path for all vertices
        while queue:
            u = self.minDistance(dist,queue)   
            queue.remove(u)
            for i in range(col):
                if self.graph[u][i] and i in queue:
                    if dist[u] + self.graph[u][i] < dist[i]:
                        dist[i] = dist[u] + self.graph[u][i]
                        self.parent[i] = u
        # print the constructed distance array
        self.printSolution(dist)
        print()

    def printPath(self,j):
        if self.parent[j] == -1 :
            print(j, end=" ")
            return
        self.printPath(self.parent[j])
        print(j, end=" ")
    
    def printSolution(self, dist):
        src = 0
        print("Vertex \t\t   Distance from Source  \t  Path")
        for i in range(1, len(dist)):
            print(f"\n{src} --> {i}  \t\t {dist[i]}  \t\t\t\t\t",end ="")
            self.printPath(i)

    def print_graph(self):
        for i in self.graph:
            print(i)

graph = Graph(5)
graph.print_graph()
while True:
    u,v,w = input().split()
    if (u!='n' or v!='n' or w!='n'):
        graph.add_weighted_undirected_edge(int(u),int(v),int(w))
    else:
        break
graph.print_graph()
graph.dijkstra(0)

