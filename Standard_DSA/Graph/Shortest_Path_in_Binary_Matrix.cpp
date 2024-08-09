class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {

        if(grid[0][0]==1)
        return -1;


        int m=grid.size();
        int n=grid[0].size();

        if(m==1 && n==1)
        return 1;

        int distance=1;

        queue<pair<int,int>>qu;

        pair<int,int>pr;

        qu.push({0,0});

        vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>movement={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

        visited[0][0]=true;

        while(!qu.empty())
        {
            int sz=qu.size();
            int i=0;

            while(i<sz)
            {
               pr=qu.front();
               qu.pop();
               int x=pr.first;
               int y=pr.second;

               int xx,yy;
               for(auto mv:movement)
               {
                   xx=x+mv[0];
                   yy=y+mv[1];

                if(xx>=0 && xx<m && yy>=0 && yy<n && !visited[xx][yy] && grid[xx][yy]==0)
                {
                    if(xx==m-1 && yy==n-1)
                    {
                        return distance+1;
                    }
                    visited[xx][yy]=true;
                    qu.push({xx,yy});
                }

               }


               i+=1;
            }
            distance+=1;

        }

        return -1;


    }
};