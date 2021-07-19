class PriorityQueue(object):
    def __init__(self):
        self.queue = []
  
    def __str__(self):
        return ' '.join([str(i) for i in self.queue])
  
    # for checking if the queue is empty
    def isEmpty(self):
        return len(self.queue) == 0
  
    # for inserting an element in the queue
    def insert(self, data):
        self.queue.append(data)
  
    # for popping an element based on Priority
    def delete(self):
        try:
            min = 0
            for i in range(len(self.queue)):
                if self.queue[i] < self.queue[min]:
                    min = i
            item = self.queue[min]
            del self.queue[min]
            return item
        except IndexError:
            print()
            exit()

def optimalpattern(sarr):
    pq = PriorityQueue()
    for i in sarr:
        pq.insert(i)

    cost = 0
    while(len(pq.queue) > 1):
        a = pq.delete()
        b = pq.delete()
        t = a+b
        cost = cost + t
        pq.insert(t)
    
    print(f"Total Cost (Minimum computations): {cost}")
    print(f"Final element after merging {pq}")


sarr = [1,2,3,4,10]
optimalpattern(sarr)


