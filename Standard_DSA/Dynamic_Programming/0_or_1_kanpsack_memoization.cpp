int mymaxm_knapsack(int i,int w,int wt[],int val[],vector<vector<int>>&dp)
    {
        if(i<0)
        return 0;

        if(dp[i][w]!=-1)
        return dp[i][w];

        //dp[i][w]=max(mymaxm_knapsack(i-1,w,wt,val,dp),val[i]+mymaxm_knapsack(i-1,w-wt[i],wt,val,dp));

        int not_take=0;

        not_take=mymaxm_knapsack(i-1,w,wt,val,dp);

        //take

        int take=0;

        if(w>=wt[i])
        {
            take=val[i]+mymaxm_knapsack(i-1,w-wt[i],wt,val,dp);
        }

        dp[i][w]=max(take,not_take);



        return dp[i][w];
    }

    int knapSack(int w, int wt[], int val[], int n)
    {
       // Your code here

       vector<vector<int>>dp(n,vector<int>(w+1,-1));

       return mymaxm_knapsack(n-1,w,wt,val,dp);

    }