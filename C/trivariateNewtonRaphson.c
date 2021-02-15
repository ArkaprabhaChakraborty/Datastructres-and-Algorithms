#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

void inverse(float mat[3][3])
{
    float det = 0.0;
    for(int i = 0; i < 3 ;i++)
    {
        det = det + (mat[0][i]*(mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3]* mat[2][(i+1)%3]));
    }
    float x[3][3];
    for(int i = 0;i < 3;i++)
    {
        for(int k = 0;k < 3;k++)
        {
            x[i][k] = ((mat[(k+1)%3][(i+1)%3] * mat[(k+2)%3][(i+2)%3]) - (mat[(k+1)%3][(i+2)%3] * mat[(k+2)%3][(i+1)%3]))/det;
        }
    }
    for(int j = 0; j < 3 ; j++)
    {
        for(int i = 0; i < 3 ; i++)
        {
            mat[j][i] = x[j][i];
        }
    }
}


void matmul(float mat[3][3],float f[3],float t[3])
{
    for(int i=0;i<3;i++)
    {
        float y = 0;
        for(int j=0;j<3;j++)
        {
            y = y + (mat[i][j]*f[j]);
        }
        t[i] = y;
    }
}

void function(float x1,float x2,float x3, float f[3])
{
    float f1 = pow(x1,2) - (2 * x1) + pow(x2 ,2) - x3 + 1;
    float f2 = (x1 * pow(x2,2)) - x1 - (3 * x2) + (x1 * x2) + 2;
    float f3 = (x1 * pow(x2 ,2)) - (3 * x3) + (x2 * pow(x3 ,2)) + (x1 * x2);
    f[0] = f1;f[1] = f2;f[2] = f3;
}

void jacobian(float j[3][3],float x1,float x2,float x3)
{
    float df1_dx1 = (2 * x1) - 2;
    float df1_dx2 = 2 * x2;
    float df1_dx3 = -1;

    float df2_dx1 = pow(x2,2) - 1; 
    float df2_dx2 = (2*x1*x2) - 3 + x3;
    float df2_dx3 = x2;

    float df3_dx1 = pow(x3, 2) + x2;
    float df3_dx2 = pow(x3, 2) + x1;
    float df3_dx3 = (2*x1*x3) - 3 + (2*x2*x3);
    j[0][0] = df1_dx1;
    j[0][1] = df1_dx2;
    j[0][2] = df1_dx3;
    j[1][0] = df2_dx1;
    j[1][1] = df2_dx2;
    j[1][2] = df2_dx3;
    j[2][0] = df3_dx1;
    j[2][1] = df3_dx2;
    j[2][2] = df3_dx3;
}

int main()
{
    float j[3][3],x1,x2,x3,x[3],f[3],t[3];
    scanf("%f",&x1);
    scanf("%f",&x2);
    scanf("%f",&x3);
    x[0] = x1;x[1] = x2;x[2] = x3;
    for(int i = 0;i<50;i++)
    {
        float alpha = 0.5;
        function(x[0],x[1],x[2],f);
        jacobian(j,x[0],x[1],x[2]);
        inverse(j);
        matmul(j,f,t);
        for(int k=0;k<3;k++)
        {
            x[k] = x[k] - (alpha * t[k]);
        }
        
        for(int l=0;l<3;l++)
        {
            printf("%f \n",x[l]);
        }
    }
    return 0;
}