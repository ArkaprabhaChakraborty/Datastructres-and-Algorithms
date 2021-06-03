"""
The defective chess board problem.
given a N x N board where N is even, there is one defective square.
The challenge is to find out whether the space can be tiled using L shaped tiles.

The algorithm here substitutes the tile number in the matrix

"""
t = 0
def tile(arr,a,b,x,y,size):
    global t
    if (size == 1):
        return
    t = t + 1
    q = size//2 

    if ((x < a + q) and (y< b+q)):
        tile(arr,a,b,x,y,q)
    else:
        arr[a+q-1][b+q-1] = t
        tile(arr,a,b,a+q-1,b+q-1,q)



    if ((x < a + q) and (y >= b+q)):
        tile(arr,a,b+q,x,y,q)
    else:
        arr[a+q-1][b+q] = t
        tile(arr,a,b+q,a+q-1,b+q,q)



    if((x >= a+q) and (y< b+q)):
        tile(arr,a+q,b,x,y,q)
    else:
        arr[a+q][a+q-1] = t
        tile(arr,a+q,b,a+q,b+q-1,q)



    if((x>=a+q)and (b>=b+q)):
        tile(arr,a+q,b+q,x,y,q)
    else:
        arr[a+q][b+q] = t
        tile(arr,a+q,b+q,a+q,b+q,q)




size = 8
board = []
for i in range(size):
    x = []
    for j in range(size):
        x.append(0)
    board.append(x)
board[0][0] = -1
for i in range(size):
    print(board[i])

print("")    
tile(board,0,0,0,0,8)
for i in range(size):
    print(board[i])






    
