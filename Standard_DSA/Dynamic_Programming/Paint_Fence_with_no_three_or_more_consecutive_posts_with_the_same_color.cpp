class Solution {
public:
    int numWays(int n, int k)
    {

        if(n==1)
        return k;

        if(n==2)
        return k*k;

        if(n>2 && k==1)
        return 0;


        // dp[i] will store the number of ways to paint i posts

        vector<int>dp(n+1,0);

        // Base cases
        dp[1]=k; //1 post, k ways to paint
        dp[2]=k*k; //2 post, each post can be painted in k ways


        // Fill dp array for each post

        for(int i=3;i<=n;i++)
        {

         // Recurrence relation
         dp[i]=(k-1)*(dp[i-1]+dp[i-2]);

        }

        return dp[n];

    }
};