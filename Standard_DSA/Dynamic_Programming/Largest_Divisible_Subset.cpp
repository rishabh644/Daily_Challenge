class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

          int n=nums.size(),i,j;

          sort(nums.begin(),nums.end());

          vector<int>dp(n,1);

          vector<int>prev(n,-1);

          vector<int>ans;

          for(i=1;i<n;i++)
          {
              for(j=0;j<i;j++)
              {
                  if(nums[i]%nums[j]==0)
                  {
                      if(dp[i]<(dp[j]+1))
                      {dp[i]=dp[j]+1;
                      prev[i]=j;
                      }
                  }
              }
          }

          int max_index=0;

          for(i=1;i<n;i++)
          {
              if(dp[i]>dp[max_index])
              max_index=i;
          }

          while(max_index!=-1)
          {
              ans.push_back(nums[max_index]);
              max_index=prev[max_index];
          }

          reverse(ans.begin(),ans.end());

          return ans;

    }
};