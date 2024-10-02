class Solution {
private:
vector<int>dir={-1,0,1,0,-1};

public:
    void dfs(int x,int y,vector<vector<int>>& grid2,vector<vector<int>>&vis2,vector<pair<int,int>>&st2)
    {
           vis2[x][y]=1;
           st2.push_back({x,y});

           for(int i=0;i<4;i++)
           {
            int X=x+dir[i];
            int Y=y+dir[i+1];

            if(X>=0 && X<grid2.size() && Y>=0 && Y<grid2[0].size() && grid2[X][Y]==1 && vis2[X][Y]==0 )
            {
                dfs(X,Y,grid2,vis2,st2);
            }

           }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
          int m=grid2.size();
          int n=grid2[0].size();

          vector<vector<int>>vis2(m,vector<int>(n,0));

          int subIslandCount=0;

          for(int i=0;i<m;i++)
          {

              for(int j=0;j<n;j++)
              {
                   if(grid2[i][j]==1 && vis2[i][j]==0)
                   {
                       vector<pair<int,int>>st2;
                       dfs(i,j,grid2,vis2,st2);

                       bool isSubIsland=true;

                       for(const auto& cell:st2)
                       {
                          int x=cell.first;
                          int y=cell.second;

                          if(grid1[x][y]==0)
                          {
                            isSubIsland=false;
                            break;
                          }

                       }

                       if(isSubIsland)
                       subIslandCount+=1;

                   }

              }

          }

          return subIslandCount;


    }
}; 