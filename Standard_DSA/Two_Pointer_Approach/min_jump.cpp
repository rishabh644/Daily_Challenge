class Solution {
public:
    int jump(vector<int>& nums)
    {
       int n=nums.size();

       if(n==1)
       return 0;

       int curr=0;
       int maxr=0;

       int ans=0;


       int i=0;

       while(i<n)
       {

            maxr=max(maxr,i+nums[i]);

            if(curr==i)
            {
               ans+=1;
               curr=maxr;
            }

            if(curr>=n-1)
            return ans;

            i+=1;
       }

       return ans;
    }
};