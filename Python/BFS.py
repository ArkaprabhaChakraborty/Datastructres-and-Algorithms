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

    def bfs(self,v):
        visited = [False] * self.vertices
        queue = []
        self.bfs_util(v,visited,queue)
        print('\n')

    def bfs_util(self,v,visited,queue):
        u = v
        queue.append(u)
        visited[u] = True
        while len(queue):
            s = queue.pop(0)
            visited[s] = True
            for i in self.graph[s]:
                if (visited[i] == False):
                    queue.append(i)
                    visited[i] = True
            print("{}".format(s),end = " ")

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

print("Enter vertex number to start BFS")
x  = int(input())

print("BFS for the graph is as follows:")
graph.bfs(x)



