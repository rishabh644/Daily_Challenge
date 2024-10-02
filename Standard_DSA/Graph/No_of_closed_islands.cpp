class Solution {
private:
    vector<int>mov={-1,0,1,0,-1};
public:
    void bfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j)
    {
        queue<pair<int,int>>qu;

        qu.push({i,j});
        vis[i][j]=1;

        int m=grid.size();
        int n=grid[0].size();

        while(!qu.empty())
        {
            auto pr=qu.front();
            qu.pop();
            int x=pr.first;
            int y=pr.second;

            for(int k=0;k<4;k++)
            {
                int xx=x+mov[k];
                int yy=y+mov[k+1];

                if(xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy]==0 && vis[xx][yy]==0)
                {
                    qu.push({xx,yy});
                    vis[xx][yy]=1;
                }

            }

        }

    }

    void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int xx,int yy)
    {
        if(xx<0 || xx>=grid.size() || yy<0 || yy>=grid[0].size() || grid[xx][yy]==1 || vis[xx][yy]==1)
        return;

        vis[xx][yy]=1;

        for(int i=0;i<4;i++)
        dfs(grid,vis,xx+mov[i],yy+mov[i+1]);
    }

    int closedIsland(vector<vector<int>>& grid)
    {

      int m=grid.size();
      int n=grid[0].size();

      vector<vector<int>>vis(m,vector<int>(n,0));

      // top row
      // and bottom row
      for(int j=0;j<n;j++)
      {

        if(grid[0][j]==0 && vis[0][j]==0)
        dfs(grid,vis,0,j);
        if(grid[m-1][j]==0 && vis[m-1][j]==0)
        dfs(grid,vis,m-1,j);

      }
      // left col and right col
      for(int i=0;i<m;i++)
      {
        if(grid[i][0]==0 && vis[i][0]==0)
        dfs(grid,vis,i,0);

        if(grid[i][n-1]==0 && vis[i][n-1]==0)
        dfs(grid,vis,i,n-1);

      }

      int ans=0;

      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++)
        {
             if(grid[i][j]==0 && vis[i][j]==0)
             {
                dfs(grid,vis,i,j);
                ans+=1;
             }
        }
      }

       return ans;

    }
};
///
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visit(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visit[i][j] && dfs(i, j, m, n, grid, visit)) {
                    count++;
                }
            }
        }
        return count;
    }

    bool dfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }
        if (grid[x][y] == 1 || visit[x][y]) {
            return true;
        }

        visit[x][y] = true;
        bool isClosed = true;
        vector<int> dirx {0, 1, 0, -1};
        vector<int> diry {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int r = x + dirx[i];
            int c = y + diry[i];
            if (!dfs(r, c, m, n, grid, visit)) {
                isClosed = false;
            }
        }

        return isClosed;
    }
};
////
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visit[i][j] && bfs(i, j, m, n, grid, visit)) {
                    count++;
                }
            }
        }
        return count;
    }

    bool bfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visit[x][y] = 2;
        bool isClosed = true;

        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};

        while (!q.empty()) {
            x = q.front().first;   // row nnumber
            y = q.front().second;  // column number
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = x + dirx[i];
                int c = y + diry[i];
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    // (x, y) is a boundary cell.
                    isClosed = false;
                } else if (grid[r][c] == 0 && !visit[r][c]) {
                    q.push({r, c});
                    visit[r][c] = true;
                }
            }
        }

        return isClosed;
    }
};
////