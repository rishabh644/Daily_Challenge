class SegmentTree:
    def __init__(self,data):
        self.n=len(data)
        #calculate the size of the segment tree array
        size=2*(2**(self.n-1).bit_length())-1
        self.segTree=[0]*size
        self.build(data,0,self.n-1,0)

    def build(self,data,low,high,pos):
        if low==high:
            #Leaf node
            self.segTree[pos]=data[low]
            return
        mid=(low+high)//2

        # Recursively build the left and right subtrees
        self.build(data,low,mid,2*pos+1)
        self.build(data,mid+1,high,2*pos+2)

        #Internal node will have the sum of the two children

        self.segTree[pos]=self.segTree[2*pos+1]+self.segTree[2*pos+2]

    def range_query(self,qlow,qhigh):
        return self._range_query(0,self.n-1,qlow,qhigh,0)

    def _range_query(self,low,high,qlow,qhigh,pos):
        # Total overlap
        if qlow<=low and qhigh>=high:
            return self.segTree[pos]

        # No overlap
        if qlow>high or qhigh<low:
            return 0

        # Partial overlap
        mid=(low+high)//2

        return self._range_query(low,mid,qlow,qhigh,2*pos+1)+self._range_query(mid+1,high,qlow,qhigh,2*pos+2)

    def update(self,idx,value):
        return self._update(0,self.n-1,idx,value,0)

    def _update(self,low,high,idx,value,pos):
        if low==high:
            self.segTree[pos]=value
            return
        mid=(low+high)//2
        if idx<=mid:
            self._update(low,mid,idx,value,2*pos+1)
        else:
            self._update(mid+1,high,idx,value,2*pos+2)

        self.segTree[pos]=self.segTree[2*pos+1]+self.segTree[2*pos+2]

# Example Usage

arr=[1,3,5,7,9,11]

seg_tree=SegmentTree(arr)

#Query Example
for (ind,key) in enumerate(arr):
    print("({},{})".format(ind,key),end=" ")
print(end='\n')
for (ind,key) in enumerate(seg_tree.segTree):
    print("({},{})".format(ind,key),end=" ")
print(end='\n')
print("Sum of values in range[1,3]: ",seg_tree.range_query(1,3)) #Output: 15 (3+5+7)
print("Sum of values in range [0,5]:",seg_tree.range_query(0,5)) #Output: 36 (1+3+5+7+9+11)

#Update example

seg_tree.update(2,10) # Update index 2 to value 10

print("Sum of values in range [1,3] after update:", seg_tree.range_query(1,3)) #Output:20 (3+10+7)
print("Sum of values in range [0,5] after update:",seg_tree.range_query(0,5)) #Output: 41 (1+3+10+7+9+11)
