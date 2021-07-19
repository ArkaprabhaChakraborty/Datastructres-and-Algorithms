"""
The Knapsack algorithm
"""

def knappartition(fraction,profit,weight,l,r):
    pivot = r
    i = l-1 #hotfix to ensure we don't skip the first element
    while(l < r):
        if(fraction[l]<fraction[pivot]):
            i = i+1 # i can be at -1  
            temp = fraction[i] 
            fraction[i] = fraction[l]
            fraction[l] = temp
            temp = profit[i]
            profit[i] = profit[l]
            profit[l] = temp
            temp = weight[i]
            weight[i] = weight[l]
            weight[l] = temp
             
        #increment l till pivot-1 as we want to position pivot element
        l = l + 1
    temp = fraction[i+1]
    fraction[i+1] = fraction[pivot]
    fraction[pivot] = temp
    temp = profit[i+1]
    profit[i+1] = profit[pivot]
    profit[pivot] = temp
    temp = weight[i+1]
    weight[i+1] = weight[l]
    weight[pivot] = temp        
    return (i+1)

def knapsort(fraction,profit,weight,l,r):
    if l < r:
        mid = knappartition(fraction,profit,weight,l,r)
        #since mid has the correct element at its position
        knapsort(fraction,profit,weight,l,mid-1)
        knapsort(fraction,profit,weight,mid+1,r)




def knapsack(weights,profits,capacity):
    fractions = []
    for i in range(len(weights)):
        fractions.append(profits[i]/weights[i])
    knapsort(fractions,profits,weights,0,len(weights)-1)
    x = [0]*len(weights)
    for i in range(len(weights)-1,-1,-1):
        if(weights[i]>capacity):
            break
        x[i] = 1
        capacity = capacity - weights[i]
    if(i<len(weights)):
        x[i] = capacity/weights[i]

    p = 0
    for i in range(len(x)-1,-1,-1):
        p = p + fractions[i]* weights[i]*x[i]
        print(f"{x[i]} fraction of item of cost {profits[i]} and weight {weights[i]} filled")
    print(f"Total Profit: {p}")


#test driver
weights = [18,10,15]
profits = [25,15,24]
cap = 25
knapsack(weights,profits,cap)