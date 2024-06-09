import heapq


class Solution:
    #Function to merge k sorted arrays.

    def mergeKArrays(self,arr,K):
        # Resultant merged list
        result=[]

        # Min-heap
        min_heap=[]

        # Insert the first element of each array into the heap
        for i in range(K):
            if len(arr[i]) >0:
                # (element,array index,element index)
                heapq.heappush(min_heap,(arr[i][0],i,0))

        # While the heap is not empty
        while min_heap:
            # Extract the smallest element
            val,arr_idx,ele_idx=heapq.heappop(min_heap)
            result.append(val)

            #If there are more elements in the array

            if ele_idx+1<len(arr[arr_idx]):
                next_val=arr[arr_idx][ele_idx+1]
                heapq.heappush(min_heap,(next_val,arr_idx,ele_idx+1))
        return result
