class Solution {
public:
    int ans=INT_MAX;
    void minimum_energy(int x,int y,int m,int n,int curEner,int rqdEner,vector<vector<int>>&dungeon)
    {
        if(x>=m || y>=n)
        return;

        curEner+=dungeon[x][y];

        if(curEner<0)
        {
          rqdEner=max(abs(curEner)+1,rqdEner);
        }
        if(x==m-1 && y==n-1)
        {
         ans=min(ans,rqdEner);
         return;
        }
       minimum_energy(x+1,y,m,n,curEner,rqdEner,dungeon);
       minimum_energy(x,y+1,m,n,curEner,rqdEner,dungeon);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
         int m=dungeon.size();
         int n=dungeon[0].size();
         int curEner=0;
         int reqdEner=1;
         minimum_energy(0,0,m,n,curEner,reqdEner,dungeon);
         minimum_energy(0,0,m,n,curEner,reqdEner,dungeon);
         return ans;
    }
};
///////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
         int m=dungeon.size();
         int n=dungeon[0].size();

         // DP table to store minimum health required at each cell
         vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
         // dp[i][j] denotes minimum energy to reach [i][j]
         // Start with the cell to the right and below the bottom-right corner

         dp[m][n-1]=dp[m-1][n]=1;

         // Fill the DP table from bottom-right to top-left

         for(int i=m-1;i>=0;i--)
         {
             for(int j=n-1;j>=0;j--)
             {

                int min_health_on_exit=min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=max(min_health_on_exit-dungeon[i][j],1);

             }

         }

         // The answer will be the minimum health needed at the top-left corner
         return dp[0][0];

    }
};