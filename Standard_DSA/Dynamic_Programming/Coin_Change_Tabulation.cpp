int coinChange(vector<int>& coins, int amount)
    {


           int n=coins.size();

           vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));

           for(int i=0;i<=n;i++)
           {
             dp[i][0]=0;
           }



           for(int i=1;i<=n;i++)
           {
              for(int am=1;am<=amount;am++)
              {
                    dp[i][am]=dp[i-1][am];

                    if(am>=coins[i-1])
                    {
                        if(dp[i][am-coins[i-1]]!=INT_MAX)

                        dp[i][am]=min(dp[i][am],1+dp[i][am-coins[i-1]]);
                    }
              }

           }



           return dp[n][amount]==INT_MAX?-1:dp[n][amount];

    }