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
                print("-> {} , ".format(j),end=" ")
            print()


    def dfs_util(self,visited,v,tsort):
        visited.add(v)
        n = self.graph[v]
        if (len(n) == 0) or (v not in tsort):
            tsort.append(v)
        for i in n:
            if i not in visited:
                self.dfs_util(visited,i,tsort)

    def dfs(self,v):
        visited = set()
        tsort = []
        while len(visited) != len(self.vertices):
            self.dfs_util(visited,v,tsort)
        print(tsort)


print("Enter Vertices list")
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

print("Enter vertex number to start Topological sort")
x  = input()

print("Topological arrangement is as follows for the graph is as follows:")
graph.dfs(x)

