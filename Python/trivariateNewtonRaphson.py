x1,x2,x3 = map(int,input().split())

def inverse(j):
    det = 0
    for i in range(3):
        det = det + (j[0][i]*(j[1][(i+1)%3] * j[2][(i+2)%3] - j[1][(i+2)%3]* j[2][(i+1)%3]))
    x = []
    for i in range(3):
        y = []
        for k in range(3):
            y.append(((j[(k+1)%3][(i+1)%3] * j[(k+2)%3][(i+2)%3]) - (j[(k+1)%3][(i+2)%3] * j[(k+2)%3][(i+1)%3]))/det)
        x.append(y)
    return x

def matmul(mat,f):
    x = []
    for i in range(3):
        y = 0
        for j in range(3):
            y = y + mat[i][j] * f[j]
        x.append(y)
    return x

def Function(x1,x2,x3):
    f1 = (x1 ** 2) - (2 * x1) + (x2 ** 2) - x3 + 1
    f2 = (x1 * (x2 ** 2)) - x1 - (3 * x2) + (x1 * x2) + 2
    f3 = (x1 * (x2 ** 2)) - (3 * x3) + (x2 * (x3 ** 2)) + (x1 * x2)
    F = [f1,f2,f3]
    return F

def jacobian(x1,x2,x3):    
    df1_dx1 = (2 * x1) - 2
    df1_dx2 = 2 * x2
    df1_dx3 = -1

    df2_dx1 = (x2 ** 2) - 1 
    df2_dx2 = (2*x1*x2) - 3 + x3
    df2_dx3 = x2

    df3_dx1 = (x3 ** 2) + x2
    df3_dx2 = (x3 ** 2) + x1
    df3_dx3 = (2*x1*x3) - 3 + (2*x2*x3)
    j = [[df1_dx1,df1_dx2,df1_dx3],[df2_dx1,df2_dx2,df2_dx3],[df3_dx1,df3_dx2,df3_dx3]]
    return j


x = [x1,x2,x3]
for i in range(50):
    alpha = 0.5
    j = jacobian(x[0],x[1],x[2])
    F = Function(x[0],x[1],x[2])
    j_inv = inverse(j)
    t = matmul(j_inv,F)
    for j in range(3):
        x[j] = x[j] - alpha*t[j]    
print(x)