class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here

        vector<vector<int>>dp(N+1,vector<int>(W+1,0));


        for(int i=1;i<=N;i++)
        {
            for(int w=1;w<=W;w++)
            {
                dp[i][w]=dp[i-1][w];

                if(w>=wt[i-1])
                {
                dp[i][w]=max(dp[i][w],dp[i][w-wt[i-1]]+val[i-1]);
                }

            }
        }


        return dp[N][W];

    }
};