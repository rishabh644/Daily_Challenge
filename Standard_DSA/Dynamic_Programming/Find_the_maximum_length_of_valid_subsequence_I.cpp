int maximumLength(vector<int>& A) {
        int k=2;
        vector<vector<int>>dp(k,vector<int>(k,0));

        int res=0;

        for(int a:A)
        {

            for(int b=0;b<k;b++)
            {
              dp[b][a%k]=max(dp[b][a%k],dp[a%k][b]+1);
              res=max(res,dp[b][a%k]);
            }

        }


        return res;

    }