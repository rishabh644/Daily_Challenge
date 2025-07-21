class Solution {
public:
    int bfs(vector<vector<int>>& rooms,vector<vector<int>>&adjl,int src)
    {
        int cnt=1;

        queue<int>qu;

        vector<int>vis(rooms.size(),0);
        vis[src]=1;
        qu.push(src);


        while(!qu.empty())
        {

          int ver=qu.front();
          qu.pop();

          for(auto adjv:adjl[ver])
          {
              if(vis[adjv]==0)
              {
                vis[adjv]=1;
                qu.push(adjv);
                cnt+=1;
              }

          }

        }

        return cnt;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {

        int n=rooms.size();

        vector<vector<int>>adjl(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                adjl[i].push_back(rooms[i][j]);
            }
        }

        int cntv=bfs(rooms,adjl,0);

        return cntv==n?true:false;

    }
};