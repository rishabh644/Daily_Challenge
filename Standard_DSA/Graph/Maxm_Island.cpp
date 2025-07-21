class Solution {

public:

    int dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int x,int y)
    {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==0 || vis[x][y])
        return 0;

        int cnt=1;
        vis[x][y]=1;

        cnt+=dfs(grid,vis,x-1,y);
        cnt+=dfs(grid,vis,x,y+1);
        cnt+=dfs(grid,vis,x+1,y);
        cnt+=dfs(grid,vis,x,y-1);

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

      int m=grid.size();
      int n=grid[0].size();

      vector<vector<bool>>vis(m,vector<bool>(n,false));

      int ans=0;

      for(int i=0;i<m;i++)
      {

        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1 && !vis[i][j])
            ans=max(ans,dfs(grid,vis,i,j));
        }

      }

      return ans;
    }
};