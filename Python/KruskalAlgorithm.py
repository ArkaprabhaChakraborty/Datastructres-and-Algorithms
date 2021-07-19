class Graph:
    def __init__(self,v):
        self.vertices = v
        self.graph = [[100000000000 for i in range(v)] for i in range(v)]
        self.parent = [i for i in range(v)]

    def add_weighted_undirected_edge(self,u,v,w):
        self.graph[u][v] = w
        self.graph[v][u] = w
    
    def find(self,a):
        while(self.parent[a]!=a):
            a = self.parent[a]
        return a
    
    def union(self,a,b):
        i = self.find(a)
        j = self.find(b)
        self.parent[i] = j

    def KruskalsMST(self):
        mincost = 0
        edge_count = 0
        while edge_count < self.vertices - 1:
            min = 100000000000
            a = -1
            b = -1
            for i in range(self.vertices):
                for j in range(self.vertices):
                    if self.find(i) != self.find(j) and self.graph[i][j] < min:
                        min = self.graph[i][j]
                        a = i
                        b = j
            self.union(a, b)
            print('Edge {}:({}, {}) cost:{}'.format(edge_count, a, b, min))
            edge_count += 1
            mincost += min
        print("Minimum cost= {}".format(mincost))
    
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

graph.KruskalsMST()

