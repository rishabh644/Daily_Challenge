import heapq

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap=[]
        n=len(lists)
        ans=[]
        for index,node in enumerate(lists):
            if node:
                heapq.heappush(heap,(node.val,index,node))
        # Create a dummy node to start the merged list

        dummy=ListNode()
        current=dummy

        # Continue until the heap is empty
        while(heap):
            # Pop the smallest node from the heap
            val,index,node=heapq.heappop(heap)
            # Append the node to the merged list
            current.next=ListNode(val)
            # Move the current pointer to the newly added node
            current=current.next
            #If there are remaining elements in the popped node's list
            #push the next element into the heap

            if node.next:
                heapq.heappush(heap,(node.next.val,index,node.next))

        # Return the merged list starting from the next of the dummy node
        return dummy.next


def main():
    obj=Solution()
    ls=[]
    dummy=ListNode()
    current=dummy
    current.next=ListNode(1)
    current=current.next
    current.next=ListNode(4)
    current=current.next
    current.next=ListNode(5)
    current=current.next
    ls.append(dummy.next)
    dummy=ListNode()
    current=dummy
    current.next=ListNode(1)
    current=current.next
    current.next=ListNode(3)
    current=current.next
    current.next=ListNode(4)
    current=current.next
    ls.append(dummy.next)
    dummy=ListNode()
    current=dummy
    current.next=ListNode(2)
    current=current.next
    current.next=ListNode(6)
    current=current.next
    ls.append(dummy)

    nodeptr=obj.mergeKLists(ls)
    while nodeptr.next:
        print(nodeptr.val,' -> ',end='')
        nodeptr=nodeptr.next

main()
