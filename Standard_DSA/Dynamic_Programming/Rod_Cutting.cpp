    int mymaxProfit(int len,int price[],vector<int>&dp)
    {
        // Base case: if the rod length is 0, the maximum profit is 0

        if(len==0)
        return 0;

        // If the subproblem has already been solved,return the stored result

        if(dp[len]!=-1)
        return dp[len];

        int maxProfit=0;

        // Try different cut lengths and choose the one that gives the maximum profit

        for(int i=1;i<=len;i++)
        {

            if(i<=len)
            {
                maxProfit=max(maxProfit,price[i-1]+mymaxProfit(len-i,price,dp));
            }


        }

        // Store the result in the memoization table



        dp[len]=maxProfit;
        return maxProfit;


    }

    int cutRod(int price[], int n) {
        //code here

        // Create a memoization table to store results of subproblems

        vector<int>dp(n+1,-1);

        return mymaxProfit(n,price,dp);


    }