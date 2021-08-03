#include <stdio.h>
#include <limits.h>

void printParenthesis(int i, int j, int n, int *bracket, char* name)
{
    // If only one matrix left in current segment
    if (i == j)
    {
        printf("%c", (*name)++);
        return;
    }

    printf("(");

    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);

    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    printf( ")");
}

void matrixChainOrder(int p[], int n)
{
    /*
        * 0th row and 0th column of m[][]
        * are not used, just done for simplicity of code
        * (Yes it probably increases axillary space)
    */
    int m[n][n];

    /*
        * bracket[i][j] stores optimal break point in
        * subexpression from i to j.
    */
    int bracket[n][n];

    // cost is zero when multiplying one matrix.
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is used for the chain length.
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                // q = cost of the scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    char name = 'A';

    printf("Optimal Parenthesization is : ");
    printParenthesis(1, n - 1, n, (int *)bracket, &name);
    printf("\nOptimal Cost is : %d \n",m[1][n - 1]);
}


int main()
{
    int arr[] = {30, 35, 15, 5, 10, 20 , 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    matrixChainOrder(arr, n);
    return 0;
}