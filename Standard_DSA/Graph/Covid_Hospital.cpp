class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here

        queue<pair<pair<int,int>,int>>qu;

        int m=hospital.size();
        int n=hospital[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<vector<int>>time_taken(m,vector<int>(n,0));


        vector<pair<int,int>>mov={{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(hospital[i][j]==2)
               {
                   visited[i][j]=1;
                   time_taken[i][j]=0;

                   qu.push({{i,j},0});
               }

            }
        }

        while(!qu.empty())
        {
            int sz=qu.size();

            for(int i=0;i<sz;i++)
            {
                 pair<pair<int,int>,int>p=qu.front();
                 int x=p.first.first;
                 int y=p.first.second;
                 qu.pop();
                 int xx,yy;

                 for(auto mv:mov)
                 {
                     xx=mv.first+x;
                     yy=mv.second+y;

                     if(xx>=0 && xx<m && yy>=0 && yy<n && hospital[xx][yy]==1 && visited[xx][yy]==0 )
                     {
                         visited[xx][yy]=1;
                         time_taken[xx][yy]=p.second+1;

                         qu.push({{xx,yy},p.second+1});
                     }

                 }

            }


        }
        int mx=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(hospital[i][j]==1 && time_taken[i][j]==0)
                return -1;
                else
                {
                    mx=max(mx,time_taken[i][j]);
                }


            }
        }

        return mx;
    }