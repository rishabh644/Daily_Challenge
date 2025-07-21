class Solution {
public:

    int minCost(vector<int>& cost,int ind)
    {
        if(ind>=cost.size())
        return 0;

        return cost[ind]+min(minCost(cost,ind+1),minCost(cost,ind+2));
    }

    int minCostClimbingStairs(vector<int>& cost)
    {

        int i=0;

        return min(minCost(cost,i),minCost(cost,i+1));


    }
};
/////////////////////////////////////////////////////////////////////
class Solution {
public:

    int minCost(vector<int>& cost,int ind,vector<int>&dp)
    {
        if(ind>=cost.size())
        return 0;

        if(dp[ind]!=-1)
        return dp[ind];

        dp[ind]=cost[ind]+min(minCost(cost,ind+1,dp),minCost(cost,ind+2,dp));

        return dp[ind];
    }

    int minCostClimbingStairs(vector<int>& cost)
    {

        int i=0;
        vector<int>dp(cost.size(),-1);
        return min(minCost(cost,i,dp),minCost(cost,i+1,dp));


    }
};
//////////////////////////////////////////////////////////////////////////
class Solution {
public:

    int minCost(vector<int>& cost,int ind,vector<int>&dp)
    {
        if(ind>=cost.size())
        return 0;

        if(dp[ind]!=-1)
        return dp[ind];

        dp[ind]=cost[ind]+min(minCost(cost,ind+1,dp),minCost(cost,ind+2,dp));

        return dp[ind];
    }

    int minCostClimbingStairs(vector<int>& cost)
    {

        int i=0;
        int n=cost.size();
        vector<int>dp(n+1,-1);
        dp[n]=0;
        dp[n-1]=cost[n-1];

        for(int i=n-2;i>=0;i--)
        {
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }

        return min(dp[0],dp[1]);



    }
};