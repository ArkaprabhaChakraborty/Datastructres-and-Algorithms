'''
COIN FLIP.

In this game the player will use N coins numbered from 1 to N, 
and all the coins will be facing in "Same direction" (Either Head or Tail),
which will be decided by the player before starting of the game.

The player needs to play N rounds.In the k-th round the player will flip the face of the all coins 
whose number is less than or equal to k. That is, the face of coin i will be reversed, from Head to Tail, 
or, from Tail to Head, for i ≤ k.

You need to guess the total number of coins showing a particular face after playing N rounds. 
Let's say you play G times.

The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow.
The first line of each test contains an integer G, denoting the number of games played by You. 
Each of the following G lines denotes a single game, and contains 3 space separeted integers I, N, Q, 
where I denotes the initial state of the coins, 
N denotes the number of coins and rounds, 
and Q, which is either 1, or 2 as explained below.

Here I=1 means all coins are showing Head in the start of the game, 
and I=2 means all coins are showing Tail in the start of the game. 

Q=1 means You need to guess the total number of coins showing Head in the end of the game, 
and Q=2 means You need to guess the total number of coins showing Tail in the end of the game.

Input:
1
2
1 5 1
1 5 2

Output:
2
3
'''
t = int(input())
for z in range(t):
    g = int(input())
    for y in range(g):
        i,n,q = map(int,input().split())
        h_count = 0
        t_count = 0
        if n%2 == 0:
            h_count = t_count = n//2
        else:
            if i == 1:
                t_count = (n+1)//2
                h_count = n - t_count
            else:
                h_count = (n+1)//2
                t_count = n - h_count
        if q==1:
            print(h_count)
        else:
            print(t_count)

