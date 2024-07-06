class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {

      vector<vector<int>>dp(k,vector<int>(k,0));

      int res=0;

      for(int a:nums)
      {
         for(int b=0;b<k;b++)
         {
            dp[b][a%k]=max(dp[b][a%k],dp[a%k][b]+1);

            res=max(res,dp[b][a%k]);
         }

      }

      return res;

    }
};
////////////
int maximumLength(vector<int>& nums, int k) {

        int max_length=0;

        // Iterate over each possible remainder value from 0 to k-1


        for(int t=0;t<k;t++)
        {
           // Initialize the dynamic programming array to store the maximum length for each remainder


           vector<int>dp(k,0);


           for(int i=0;i<nums.size();i++)
           {

              // Calculate the remainder of the current number when divided by k
              int c_r=nums[i]%k;


             // Calculate the remainder that would achieve the target remainder when added to the current number
              int p_r=(t+k-c_r)%k;

             // Update the dp array
              dp[c_r]=max(dp[c_r],dp[p_r]+1);

              max_length=max(max_length,dp[c_r]);

           }


        }



        return max_length;
    }