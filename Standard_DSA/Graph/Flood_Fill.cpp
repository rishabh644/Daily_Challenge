class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
       vector<int>mov={-1,0,1,0,-1};

       queue<pair<int,int>>qu;

       qu.push({sr,sc});
       int m=image.size();
       int n=image[0].size();

       vector<vector<int>>vis(m,vector<int>(n,0));
       vis[sr][sc]=1;

       while(!qu.empty())
       {
          auto pr=qu.front();

          int x=pr.first;
          int y=pr.second;

          int pc=image[x][y];
          image[x][y]=color;

          for(int i=0;i<=3;i++)
          {

            int nx=x+mov[i];
            int ny=y+mov[i+1];

            if(nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny]==pc && vis[nx][ny]==0)
            {
                qu.push({nx,ny});
                vis[nx][ny]=1;
            }

          }

          qu.pop();

       }

       return image;
    }
};