class Solution:
    def lenOfLongSubarr (self, arr, n, k) :
        #Complete the function
        dr={0:-1}
        psum=0
        ans=0
        for i in range(n):
            psum+=arr[i]

            if psum-k in dr:
                ans=max(ans,i-dr[psum-k])

            if psum not in dr:
                dr[psum]=i

        return ans
/////////////////////////////////
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K)
    {
        // Complete the function
        unordered_map<int,int>ump;
        int psum=0;

        ump[0]=-1;

        int ans=0;

        for(int i=0;i<N;i++)
        {
            psum+=A[i];
            if(ump.count(psum-K)!=0)
            {
                ans=max(ans,i-ump[psum-K]);
            }

            if(ump.count(psum)==0)
            ump[psum]=i;
        }

        return ans;

    }

};