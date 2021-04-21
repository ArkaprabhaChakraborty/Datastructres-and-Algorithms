class Graph:
    def __init__(self, V):
        self.vertices = V
        self.graph = {}
        for i in range(self.vertices):
            self.graph[i] = []
    def add_edge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def print_graph(self):
        for i in self.graph.keys():
            print("Adjacency list for vertex {} is".format(i), end = " ")
            t = self.graph[i]
            print(i,end = " ")
            for x in t:
                print("--> {}".format(x), end = " ")
            print("\n")
    def dfs(self,v):
        visited = set()
        self.dfs_util(v,visited)
        print('\n')

    def dfs_util(self,v,visited):
        visited.add(v)
        print(" {}".format(v),end = " ")
        for n in self.graph[v]:
            if n not in visited:
                self.dfs_util(n,visited)  


print("Enter the number of Vertices")
x = int(input())

graph = Graph(x)

while True:
    print("Enter source and destination(space separated) using numbers within the specified range or enter (n n) to exit")
    try:
        u,v = map(int,input().split())
        graph.add_edge(u, v)
    except: 
        break
graph.print_graph()

print("Enter vertex number to start DFS")
x  = int(input())

print("DFS for the graph is as follows:")
graph.dfs(x)