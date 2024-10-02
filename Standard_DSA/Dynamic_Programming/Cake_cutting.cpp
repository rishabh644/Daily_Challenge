class Solution {


public:
    int solve(int i,int j,int x,int y,vector<int> &hor,vector<int> &ver,vector<vector<vector<vector<int>>>> &dp){

        if(i == j&&x==y) return 0;
        if(dp[i][j][x][y] != -1) return dp[i][j][x][y];

        int mini = 1e9;

        if(i<j)
        {
            for(int k = i;k<j;k++)
            {
                mini = min(mini,ver[k] + solve(i,k,x,y,hor,ver,dp)+solve(k+1,j,x,y,hor,ver,dp));
            }

        }

        if(x<y)
        {
            for(int k = x;k<y;k++){
                mini = min(mini,hor[k] + solve(i,j,x,k,hor,ver,dp) + solve(i,j,k+1,y,hor,ver,dp));
            }
        }
        return dp[i][j][x][y] = mini;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<vector<vector<vector<int>>>> dp(21,vector<vector<vector<int>>>(21,         vector<vector<int>>(21,vector<int>(21,-1))));
        return solve(0,n-1,0,m-1,horizontalCut,verticalCut,dp);
    }
};