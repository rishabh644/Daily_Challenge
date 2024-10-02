class Solution {
public:
    void bfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>&vs)
    {

     int m=grid.size();
     int n=grid[0].size();

     queue<pair<int,int>>qu;
     qu.push({x,y});
     vs[x][y]=1;

     vector<int>mov={-1,0,1,0,-1};

     while(!qu.empty())
     {
       auto pr=qu.front();
       qu.pop();
       int i=pr.first;
       int j=pr.second;
       // to move/check adjacent
       for(int k=0;k<=3;k++)
       {

        int nx=i+mov[k];
        int ny=j+mov[k+1];

        if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1' && vs[nx][ny]==0)
        {
           qu.push({nx,ny});
           vs[nx][ny]=1;
        }


       }



     }


    }
    int numIslands(vector<vector<char>>& grid)
    {

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));

        int count=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && dp[i][j]==0)
                {
                    bfs(i,j,grid,dp);
                    count++;
                }
            }
        }

        return count;
    }
};