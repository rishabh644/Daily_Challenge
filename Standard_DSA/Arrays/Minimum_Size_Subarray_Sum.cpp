class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums)
    {

       int l=0,r=0;

       int n=nums.size();
       int sum=0;
       int ans=n+1;
       while(r<n)
       {
          sum+=nums[r];

          while(l<=r && sum>=target)
          {
            ans=min(ans,r-l+1);
            sum-=nums[l];
            l++;
          }

          r+=1;

       }

       return ans==n+1?0:ans;

    }


};