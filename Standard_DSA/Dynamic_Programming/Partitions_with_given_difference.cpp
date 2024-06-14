#define mod 1000000007

class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here

        int sum=accumulate(arr.begin(),arr.end(),0);

        if((sum+d)%2!=0)
        return 0;

        int s1=(sum+d)/2;

        vector<vector<int>>dp(n+1,vector<int>(s1+1,0));

        for(int i=0;i<=n;i++)
        dp[i][0]=1;

        for(int i=1;i<=n;i++)
        {
            for(int s=0;s<=s1;s++)
            {
                // Exclude the current element
                dp[i][s]=dp[i-1][s];

                // Include the current element if it does not exceed the current sum
                if(s>=arr[i-1])
                {
                    dp[i][s]=(dp[i][s]+dp[i-1][s-arr[i-1]]%mod)%mod;
                }

            }
        }

        // The answer is the number of ways to form the sum s1 using all n elements
        return dp[n][s1];



    }
};