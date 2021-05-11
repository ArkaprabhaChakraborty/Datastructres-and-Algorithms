class Graph:
    def __init__(self,V):
        self.vertices = V
        self.graph = {}
        for i in self.vertices:
            self.graph[i] = []

    def add_directed_edge(self,u,v):
        self.graph[u].append(v)
    
    def print_graph(self):
        x = self.graph.keys()
        for i in x:
            print("{}".format(i),end = " ")
            y = self.graph[i]
            for j in y:
                print("{}-> {} ".format(i,j),end=" ")
            print()


    def dfs(self,vnodes,v,visited):
        visited[v] == True
        n = self.graph[self.vertices[v]]
        for i in n:
            x = self.vertices.index(i)
            if visited[x] == False:
                self.dfs(vnodes,x,visited)
        vnodes.append(v)

    def topological_sort(self):
        visited = [False]*len(self.vertices)
        tsort = [0] * len(self.vertices)
        j = len(self.vertices) - 1
        for i in range(len(self.vertices)):
            if visited[i] == False:
                vnodes  = []
                self.dfs(vnodes,i,visited)
                for x in vnodes:
                    tsort[j] = x
                j = j - 1
        tsort = tsort[::-1]
        for i in tsort:
            print("{} ".format(self.vertices[i]), end=" ")
        print()


print("Enter Vertices list (begining with the leaf nodes to get a root->leaf arrangement and with root to get a leaf->root arrangement)")
x = list(input().split())

graph = Graph(x)

while True:
    print("Enter source and destination(space separated) using numbers within the specified range or enter (end end) to exit")
    try:
        u,v = input().split()
        graph.add_directed_edge(u, v)
    except: 
        break
print("The adjacency list of the graph is as follows: ")
graph.print_graph()



print("Topological arrangement is as follows for the graph is as follows:")
graph.topological_sort()

