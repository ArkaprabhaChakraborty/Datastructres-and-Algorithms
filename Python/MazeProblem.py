class Queuenode:
    def __init__(self,pt,dist):
        self.pt = pt
        self.dist = dist

class Coordinates:
    def __init__(self,x,y):
        self.x = x
        self.y = y

def isvalid(r,c,R,C):
    return (r>=0) and (c>=0) and (r<R) and (c<C)


def solve(mat,visited, src,end,R,C):
    if (mat[src.x][src.y]==0) or (mat[end.x][end.y]==0):
        print("No start or end")
        return -1
    curr = Queuenode(src,0)
    queue = []
    queue.append(curr)
    visited[src.x][src.y] = True
    dr = [-1,0,0,1]
    dc = [0,-1,1,0]
    while(queue):
        x = queue.pop(0)
        coord = x.pt
        if isvalid(coord.x,coord.y,R,C) and (coord.x == end.x) and (coord.y == end.y):
                print("Reached end")
                return x.dist
        for i in range(4):
            r = coord.x + dr[i]
            c = coord.y + dc[i]
            if(isvalid(r,c,R,C) and mat[r][c]==1 and not visited[r][c]):
                t = Coordinates(r,c)
                adjnode = Queuenode(t,x.dist + 1)
                queue.append(adjnode)
                visited[r][c] = True
    print("out of loop")
    return -1

mat = [[ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 ],
        [ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 ],
        [ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 ],
        [ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ],
        [ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 ],
        [ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 ],
        [ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 ],
        [ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 ],
        [ 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 ]]

R = 9
C = 10

visited = [[False for i in range(C)]
                       for j in range(R)]
     
src = Coordinates(0,0)
end = Coordinates(8,2)

print(solve(mat,visited,src,end,R,C))