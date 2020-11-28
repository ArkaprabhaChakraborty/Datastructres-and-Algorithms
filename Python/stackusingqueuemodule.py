#using LifoQueue from queue module
from queue import LifoQueue as lfq

#maxsize – Number of items allowed in the queue.
#empty() – Return True if the queue is empty, False otherwise.
#full() – Return True if there are maxsize items in the queue. If the queue was initialized with maxsize=0 (the default), then full() never returns True.
#get() – Remove and return an item from the queue. If queue is empty, wait until an item is available.
#get_nowait() – Return an item if one is immediately available, else raise QueueEmpty.
#put(item) – Put an item into the queue. If the queue is full, wait until a free slot is available before adding the item.
#put_nowait(item) – Put an item into the queue without blocking.
#qsize() – Return the number of items in the queue. If no free slot is immediately available, raise QueueFull.

stack = lfq(maxsize=3)
#qsize() shows the number of elements 
print(stack.qsize())
stack.put('a')
stack.put('b')
print(stack.get())

