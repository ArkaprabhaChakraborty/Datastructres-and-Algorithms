# importing the sys module 
import sys 
  
# the setrecursionlimit function is 
# used to modify the default recursion 
# limit set by python. Using this,  
# we can increase the recursion limit 
# to satisfy our needs 
  
sys.setrecursionlimit(10**6) 

def JobPartition(profit,d,Jid,l,r):
    pivot= r
    i = l-1
    while(l<r):
        if (profit[l] < profit[pivot]):
            i = i + 1
            temp = profit[i]
            profit[i] = profit[l]
            profit[l] = temp 
            
            temp = d[i]
            d[i] = d[l]
            d[l] = temp

            temp = Jid[i]
            Jid[i] = Jid[l]
            Jid[l] = temp

        l = l + 1
    
    temp = profit[i+1]
    profit[i+1] = profit[pivot]
    profit[pivot] = temp

    temp = d[i+1]
    d[i+1] = d[pivot]
    d[pivot] = temp
    
    temp = Jid[i+1]
    Jid[i+1] = Jid[pivot]
    Jid[pivot] = temp
    return i+1

def JobSort(profit,d,Jid,l,r):
    if(l<r):
        mid = JobPartition(profit,d,Jid,l,r)
        JobSort(profit,d,Jid,l,mid-1)
        JobSort(profit,d,Jid,mid+1,r)



def JobSequence(profit,d,Jid,time):
    JobSort(profit,d,Jid,0,len(profit)-1)
    profit = profit[::-1]
    d = d[::-1]
    Jid = Jid[::-1]
    result = [False] * time

 
    # To store result (Sequence of jobs)
    job = ['-1'] * time
    pr = [0]*time
    du = [0]*time
    # Iterate through all given jobs
    for i in range(len(Jid)):
        for j in range(min(time - 1, d[i] - 1), -1, -1):
            # Free slot found
            if result[j] is False:
                result[j] = True
                job[j] = Jid[i]
                pr[j] = profit[i]
                du[j] = d[i]
                break
 
    # print the sequence
    print(f"Job Id: {job}")
    print(f"Profit: {pr}")
    print(f"Duration: {du}")

 


deadline = [2,	1,	3,	2,	1]
Profit = [60, 100,	20,	40,	20]
Jid  =  [0,1,2,3,4]
JobSequence(Profit,deadline,Jid,2)



