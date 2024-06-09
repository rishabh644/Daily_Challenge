class Solution:
    def merge2array(self,ans,arr,row,k):
        i=0
        j=0
        m=len(ans)
        n=k

        t=[]

        while i<m and j<k:
            if ans[i]<arr[row][j]:
                t.append(ans[i])
                i+=1
            else:
                t.append(arr[row][j])
                j+=1

        while i<m:
            t.append(ans[i])
            i+=1
        while j<k:
            t.append(arr[row][j])
            j+=1


        i=0
        while i<len(t):
            if i<m:
                ans[i]=t[i]
            else:
                ans.append(t[i])
            i+=1



    #Function to merge k sorted arrays.
    def mergeKArrays(self, arr, K):
        # code here
        # return merged list
        ans=[]

        for i in range(K):
            ans.append(arr[0][i])

        for i in range(1,K):
            self.merge2array(ans,arr,i,K)

        return ans


#Time Complexity: K+2K+3K+4K+5K+6K+....+K.K=O(K^3)