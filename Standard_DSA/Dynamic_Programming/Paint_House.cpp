class Solution {
public:
    int mymincost(int i,int c,vector<vector<int>>&costs,vector<vector<int>>&dp)
    {
       if(i==costs.size())
       return 0;

       if(dp[i][c]!=-1)
       return dp[i][c];
       int cost=INT_MAX;
       for(int k=0;k<3;k++)
       {
         if(k!=c)
         {
            cost=min(cost,costs[i][k]+mymincost(i+1,k,costs,dp));
         }
       }

       return dp[i][c]=cost;

    }
    int minCost(vector<vector<int>>& costs)
    {
       int n=costs.size();

       vector<vector<int>>dp(n,vector<int>(3,-1));

       int mincost=INT_MAX;
       for(int k=0;k<3;k++)
       {
         mincost=min(mincost,costs[0][k]+mymincost(1,k,costs,dp));

       }

        return mincost;
    }
};

////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n+1, vector<int>(3, 0));

        // Bottom-up calculation
        for (int i = n-1; i >= 0; --i) {
            dp[i][0] = costs[i][0] + min(dp[i+1][1], dp[i+1][2]);
            dp[i][1] = costs[i][1] + min(dp[i+1][0], dp[i+1][2]);
            dp[i][2] = costs[i][2] + min(dp[i+1][0], dp[i+1][1]);
        }

        // The minimum cost starting from the first house
        return min(dp[0][0], dp[0][1], dp[0][2]);
    }
};
////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minCostII(vector<vector<int>>& costs)
    {
        int n=costs.size();
        int K=costs[0].size();
        vector<vector<int>>dp(n+1,vector<int>(K,0));


        for(int i=n-1;i>=0;i--)
        {
            for(int k=0;k<K;k++)
            {

               int nxmin=INT_MAX;

               for(int j=0;j<K;j++)
               {

                if(j!=k)
                {
                   nxmin=min(nxmin,dp[i+1][j]);
                }

               }

               dp[i][k]=costs[i][k]+nxmin;

            }

        }

        int ans=INT_MAX;

        for(int j=0;j<K;j++)
        {
            ans=min(ans,dp[0][j]);
        }

        return ans;

    }
};