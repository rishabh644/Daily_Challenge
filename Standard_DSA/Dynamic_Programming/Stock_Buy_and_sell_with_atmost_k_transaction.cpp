class Solution {
public:
    void mymaxprofit(vector<int>& prices,int k,int i,bool buy,int& ans,int crpr)
    {
        if(i==prices.size() || k==0)
        {
            ans=max(ans,crpr);
            return;
        }

        if(buy)
        {
            // buy at i
            mymaxprofit(prices,k,i+1,false,ans,crpr-prices[i]);
            // don't buy at i
            mymaxprofit(prices,k,i+1,buy,ans,crpr);
        }
        else
        {
             // sell at i
             mymaxprofit(prices,k-1,i+1,true,ans,crpr+prices[i]);
             // don't sell at i
             mymaxprofit(prices,k,i+1,buy,ans,crpr);

        }

    }
    int maxProfit(int k, vector<int>& prices)
    {
        bool buy=true;

        int ans=0;
        int crpr=0;

        mymaxprofit(prices,k,0,buy,ans,crpr);

        return ans;
    }
};
///////////////------------------------------///////////////////////////////////////-----------------------------------------------

class Solution {
public:

    int maxProfit(int k, vector<int>& prices)
    {
        int n=prices.size();

        if(n==0 || k==0)
        return 0;

        // if k is larger than n/2, we can perform unlimited transactions

        if(k>= (n/2) )
        {
             int maxProfit=0;

             for(int i=1;i<n;i++)
             {
                if(prices[i]>prices[i-1])
                {
                    maxProfit+=prices[i]-prices[i-1];
                }

             }

              return maxProfit;
        }


        // DP array to store max profit for i days, j transactions, and whether holding stock


        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));

         // Initialization

         for(int i=0;i<=k;i++)
         {
            dp[n][i][0]=dp[n][i][1]=0;
         }

         for(int i=n-1;i>=0;i--)
         {
            for(int j=1;j<=k;j++)
            {
              dp[i][j][1]=max(-prices[i]+dp[i+1][j][0],dp[i+1][j][1]); // Buy or skip
              dp[i][j][0]=max(prices[i]+dp[i+1][j-1][1],dp[i+1][j][0]); // sell or skip
            }

         }

         return dp[0][k][1];
    }
};
////////////////////////////////////////--------------------------///////////////////////////-----------------------////////////////////////////////////////-----------------------------------------
