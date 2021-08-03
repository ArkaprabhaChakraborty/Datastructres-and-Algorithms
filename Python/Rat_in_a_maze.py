'''

Rat in a maze backtracking problem.
Given a maze of zeroes and ones where 0's mark valid path and 1's mark obstacles, find the shortest path from a given source to a given destination.

'''


import sys
sys.setrecursionlimit(10**6)


def rat_travel(maze,n,source_x,source_y,dest_x,dest_y):
    solution  = [[0 for i in range(n)] for i in range(n)]
    solve_maze(maze,solution,source_x,source_y,dest_x,dest_y,n)
    print_path(solution)

def solve_maze(maze,solution,x,y,dest_x,dest_y,n):
    if(x==dest_x and y==dest_y and maze[x][y] == 0):
        solution[x][y] = 1
        return True
    if(x>=0 and y>=0 and x<n and y<n and maze[x][y]==0):
        if solution[x][y] == 1:
            return False
        solution[x][y] = 1
        if (solve_maze(maze,solution,x+1,y,dest_x,dest_y,n) == True):
            return True
        if (solve_maze(maze,solution,x,y+1,dest_x,dest_y,n) == True):
            return True
        if (solve_maze(maze,solution,x-1,y,dest_x,dest_y,n) == True):
            return True
        if (solve_maze(maze,solution,x,y-1,dest_x,dest_y,n) == True):
            return True

        solution[x][y] = 0
        return False   

def solve_maze_with_iterartions(maze,solutions,x,y,dest_x,dest_y,move_x,move_y,n):
    
    if (x>=0 and y>=0 and x<n and y<n):
        if (x == dest_x and y == dest_y and maze[x][y] == 0):
            solutions[x][y] = 1;
            return True

    if (x>=0 and y>=0 and x<n and y<n and maze[x][y] == 0):
        if solutions[x][y] == 1:
            return False
    if (x>=0 and y>=0 and x<n and y<n and maze[x][y] == 0):
        solutions[x][y] = 1
        for i in range(4):
            x = x + move_x[i]
            y = y + move_y[i]
            if(solve_maze_with_iterartions(maze,solutions,x,y,dest_x,dest_y,move_x,move_y,n) == True):
                return True
        

def rat_in_maze_iterative(maze,x,y,dest_x,dest_y,n):
    solution  = [[0 for i in range(n)] for i in range(n)]
    move_x = [1,0,0,-1]
    move_y = [0,1,-1,0]
    solve_maze_with_iterartions(maze,solution,x,y,dest_x,dest_y,move_x,move_y,n)
    print_path(solution)


def print_path(arr):
    for i in arr:
        print(i)

mazes = [[0, 1, 1, 1],
         [0, 0, 1, 0],
         [1, 0, 1, 1],
         [1, 0, 0, 0] ]
              
rat_in_maze_iterative(mazes,0,0,3,3,4)
