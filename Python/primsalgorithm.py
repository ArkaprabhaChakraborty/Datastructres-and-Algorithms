
import sys
class Graph:
    def __init__(self,v):
        self.vertices = v
        self.graph = [[0 for i in range(v)] for i in range(v)]

    def add_weighted_undirected_edge(self,u,v,w):
        self.graph[u][v] = w
        self.graph[v][u] = w

    def minweight(self,key,mst):
        min = 100000000000
        minindex = -1
        for i in range(self.vertices):
            if key[i] < min and mst[i] == False:
                min = key[i]
                minindex = i
        return minindex

    def prims(self):
        mst = [False]*self.vertices
        keys = [100000000000]*(self.vertices)
        keys[0] = 0
        parent = [0]*self.vertices
        parent[0] = -1  
        for cout in range(self.vertices):
            u = self.minweight(keys, mst)
            mst[u] = True
            for v in range(self.vertices):
                if self.graph[u][v] > 0 and mst[v] == False and keys[v] > self.graph[u][v]:
                        keys[v] = self.graph[u][v]
                        parent[v] = u
        print("Mst is :")
        for i in range(self.vertices):
            print("{}-->{} -- {}".format(parent[i],i,self.graph[i][parent[i]]))
        print()

    def print_graph(self):
        for i in self.graph:
            print(i)

x = Graph(5)
x.print_graph()
while True:
    u,v,w = input().split()
    if (u!='n' or v!='n' or w!='n'):
        x.add_weighted_undirected_edge(int(u),int(v),int(w))
    else:
        break

x.print_graph()
x.prims()
