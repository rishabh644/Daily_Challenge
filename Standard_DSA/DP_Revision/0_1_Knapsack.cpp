int knapSack(int w, vector<int>& wt, vector<int>& val)
    {
        // Your code here

        int n=wt.size();

        vector<vector<int>>dp(n+1,vector<int>(w+1,0));

        // dp[i][j] represent maximum profit you can make by using i item and maximum weight j

        for(int i=1;i<=n;i++)
        {
            int cw=wt[i-1];
            for(int j=0;j<=w;j++)
            {

                if(j<cw)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-cw]+val[i-1]);
                }

            }

        }

        return dp[n][w];

    }

//////////////////
int knapSack(int w, vector<int>& wt, vector<int>& val)
    {
        // Your code here

        int n=wt.size();

        vector<vector<int>>dp(n+1,vector<int>(w+1,0));

        // dp[i][j] represent maximum profit you can make by using i item and maximum weight j

        for(int i=1;i<=n;i++)
        {
            int cw=wt[i-1];
            for(int j=0;j<=w;j++)
            {

                if(j<cw)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-cw]+val[i-1]);
                }

            }

        }

        return dp[n][w];

    }