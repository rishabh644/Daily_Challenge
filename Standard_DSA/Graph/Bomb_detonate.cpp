class Solution {
public:
    int bfs(vector<vector<int>>&adjl,int v)
    {
        vector<int>vis(adjl.size(),0);
        queue<int>qu;
        qu.push(v);
        vis[v]=1;
        int cnt=1;
        while(!qu.empty())
        {
            int ver=qu.front();
            qu.pop();

            for(int adjv:adjl[ver])
            {
                if(vis[adjv]==0)
                {
                    qu.push(adjv);
                    vis[adjv]=1;
                    cnt+=1;

                }
            }
        }

        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs)
    {

        int N=bombs.size();

        if(N==1)
        return N;

        vector<vector<int>>adjl(N);

        auto eucld=[](int xa,int ya,int xb,int yb)
        {
            return sqrt((xb-xa)*1ll*(xb-xa)+(yb-ya)*1ll*(yb-ya));
        };

        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {

                int xa=bombs[i][0];
                int ya=bombs[i][1];
                double ra=bombs[i][2];

                int xb=bombs[j][0];
                int yb=bombs[j][1];
                double rb=bombs[j][2];

                double dis=eucld(xa,ya,xb,yb);

                if(dis<=ra)
                {
                    adjl[i].push_back(j);
                }
                if(dis<=rb)
                {
                    adjl[j].push_back(i);
                }

            }
        }

        int ans=1;



        for(int v=0;v<N;v++)
        {


                int cntv=bfs(adjl,v);
                ans=max(ans,cntv);

        }

        return ans;

    }
};