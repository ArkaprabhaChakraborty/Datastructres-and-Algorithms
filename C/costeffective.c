/*
After a long and heavy semester of studying ESC101, Alan is finally happy as he gets to go on a vacation. He is in Kanpur and wants to go to Goa. However, when he looks up the flight costs, he sees that Kanpur - Goa flight ticket costs Rs. 10,000 (Did you know that there is an airport in Kanpur ?). He is disappointed and decides to go to some other city where the flights are cheaper. However, he later finds that Kanpur - Mumbai flight ticket costs Rs. 7000 and Mumbai - Goa flight ticket costs Rs. 1000. So, by the connected flight Kanpur - Mumbai - Goa, he can reach Goa with just Rs. 8000. Now Alan is curious and wonders if there are even cheaper routes to reach Goa. He prints the list of all flight ticket costs from the airlines website. However he is too lazy to write code to find the cheapest route (he is tired from a semester of ESC101), and needs your help.

INPUT:
The first line contains an integer n, the number of cities with airline services (1 < n < 100).

The next n lines each contain n space-separated integers. Together, these n lines represent an n x n matrix Mat where each entry is a cost of a flight ticket. Mat[i][j] gives the cost of the flight from city i to j (0 <= i,j < n). Each flight ticket cost is a positive integer less than or equal to 10,000. Note that Mat[i][i] = 0 for all 0 <= i < n, obviously.

The third line contains three space separated integers h, d and k. h is the city from where Alan starts the journey (Kanpur in this example), d is the city where the journey ends (Goa in this example) and k is the maximum number of flights Alan is willing to take on the journey (this is a vacation after all). (0 <= h,d < n and 0 < k < n).

OUTPUT:
A single line containing one integer which is the minimum amount using which he can get from city h to city d in under k flights.

EXAMPLE:

Input:
4
0 2 3 1
1 0 2 2
4 2 0 1
2 2 3 0
2 0 3

Output:
3

Explanation:
We need to get from 2 to 0 in under 3 flights. The cheapest route 2 -> 1 -> 0. 
2 -> 1 costs 2 while 1 -> 0 costs 1. So total cost is 3. 
Note that there may be other paths also with total cost 3.
*/


#include <stdio.h>
#define MAX 10000


int min(int a,int b)
{
    return ((a<b)?a:b);
}

int cost(int u,int v,int arr[100][100],int visited[100],int n,int steps)
{
    if((u==v)||(steps == 0))
    {
        return 0;
    }
    visited[u] = 1;
    int ans = MAX;
    int curr = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[u][i]!=MAX && !visited[i])
        {
            curr = cost(i,v,arr,visited,n,steps-1);
            if(curr < MAX)
            {
                ans = min(ans,arr[u][i] + curr);
            }
        }
    }
    visited[u]= 0;
    return ans; 
}

int main()
{
    int arr[100][100],visited[100];
    int n,u,v,steps;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i = 0;i < n;i++)
    {
        arr[i][i] = MAX;
        visited[i] = 0;
    }
    scanf("%d",&u);
    scanf("%d",&v);
    scanf("%d",&steps);
    int c = cost(u,v,arr,visited,n,steps);
    printf("%d\n",c);
    return 0;
}

