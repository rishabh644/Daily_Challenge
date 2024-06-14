int my_maxm_knapsack(int i,int W,int val[],int wt[],vector<vector<int>>&dp)
    {

        if(i<0)
        return 0;

        if(dp[i][W]!=-1)
        {
                return dp[i][W];
        }

        // don't take

        int donttake=my_maxm_knapsack(i-1,W,val,wt,dp);


        // take
        int take=0;

        if(W>=wt[i])
        take=val[i]+my_maxm_knapsack(i,W-wt[i],val,wt,dp);

        int result;

        result=max(donttake,take);

        dp[i][W]=result;

        return result;

    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here

         vector<vector<int>>dp(N,vector<int>(W+1,-1));


        // for(int i=1;i<=N;i++)
        // {
        //     for(int w=1;w<=W;w++)
        //     {
        //         dp[i][w]=dp[i-1][w];

        //         if(w>=wt[i-1])
        //         {
        //         dp[i][w]=max(dp[i][w],dp[i][w-wt[i-1]]+val[i-1]);
        //         }

        //     }
        // }


        // return dp[N][W];

        return my_maxm_knapsack(N-1,W,val,wt,dp);


    }