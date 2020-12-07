'''
You are developing a smartphone app. 
You have a list of potential customers for your app. 
Each customer has a budget and will buy the app at your declared price if and only if 
the price is less than or equal to the customer's budget.

You want to fix a price so that the revenue you earn from the app is maximized. 
Find this maximum possible revenue.

For instance, suppose you have 4 potential customers and their budgets are 30, 20, 53 and 14. 
In this case, the maximum revenue you can get is 60 .

Sample Input 1
4
30
20
53
14

Sample Output 1
60

Sample Input 2
5
40
3
65
33
21

Sample Output 2
99
'''
# Approach: we sort the array in descending order
# then we simply iterate over the array elements by multiplying with their position + 1 value to get 
# the maximised value of A * B where A is the price and B is the number of people 
t = int(input())
l = []
for i in range(t):
    l.append(int(input()))
l.sort(reverse = True)
prod = 0
i = 0
while i < t:
    s = (i+1)*l[i]
    if prod < s:
        prod = s
    i = i + 1
print(prod)