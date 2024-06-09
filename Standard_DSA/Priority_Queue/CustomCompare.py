import heapq

class CustomCompare:
    def __init__(self,value,priority):
        self.value=value
        self.priority=priority

    def __lt__(self,other):
        #Define custom comparison logic
        return self.priority>other.priority

    def __repr__(self):
        return f'{self.value}({self.priority})'

#Example Usage

items=[CustomCompare('apple',5),CustomCompare('banana',2),CustomCompare('cherry',3)]

heap=[]

for item in items:
    heapq.heappush(heap,item)


#Printing the heap to see the internal structure

print(heap)

#Pop elements to see the order

print(heapq.heappop(heap)) #Output: apple(5)
print(heapq.heappop(heap)) #Output: cherry(3)
print(heapq.heappop(heap)) #Output: banana(2)
