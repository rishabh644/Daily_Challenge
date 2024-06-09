# You are given an array arr of N
# integers representing a min Heap.
# The task is to convert it to max Heap.
# A max-heap is a complete binary tree in
# which the value in each internal node is
# greater than or equal to
# the values in the children of that node.

class Solution:

    def swap(self,arr,i,j):
        arr[i],arr[j]=arr[j],arr[i]

    def maxHeapify(self,arr,i,N):
        l=2*i+1
        r=2*i+2
        ind=i
        if(l<N and arr[l]>arr[ind]):
            ind=l
        if(r<N and arr[r]>arr[ind]):
            ind=r
        if(ind!=i):
            self.swap(arr,ind,i)
            self.maxHeapify(arr,ind,N)

    def convertMinToMaxHeap(self, N, arr):
        for i in range((N-1)//2,-1,-1):
            self.maxHeapify(arr,i,N)