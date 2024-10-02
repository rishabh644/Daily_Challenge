class Solution {
public:

    int MaxProfit(vector<int>&prices,int indx,bool buy,vector<vector<int>>&dp)
    {
         if(indx>=prices.size())
         return 0;

         if(dp[indx][buy]!=-1)
         return dp[indx][buy];

         if(buy)
         {
            return dp[indx][buy]=max(-1*prices[indx]+MaxProfit(prices,indx+1,false,dp),MaxProfit(prices,indx+1,buy,dp));
         }
         else
         {
           return dp[indx][buy]=max(prices[indx]+MaxProfit(prices,indx+2,true,dp),MaxProfit(prices,indx+1,false,dp));
         }

    }

    int maxProfit(vector<int>& prices)
    {
        int i=0;
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return MaxProfit(prices,i,true,dp);
    }
};

//////////////////////////////////-----------------------------------------///////////////////////////////////---------------------------------////////////////////////////////////-------------------------------
class Solution {
public:


    int maxProfit(vector<int>& prices)
    {
        int i=0;
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        for(int i=n-1;i>=0;i--)
        {
            //buy at i

            dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);

            //sell at i

            dp[i][0]=dp[i+1][0];
            if(i+2<=n)
            dp[i][0]=max(dp[i+1][0],prices[i]+dp[i+2][1]);
            else
            dp[i][0]=max(dp[i+1][0],prices[i]);

        }

        return dp[0][1];

    }
};
/////////////////////////-----------------///////////////