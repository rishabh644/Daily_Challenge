class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        int N=n+1;

        vector< vector< pair<int,int> > >adjl(N,vector<pair<int,int>>());

        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];

            adjl[u].push_back({v,wt});
        }

        vector<int>distance(N,INT_MAX);

        distance[k]=0;

        queue<pair<int,int>>qu;

        qu.push({k,0});

        pair<int,int>pr;

        while(!qu.empty())
        {
            pr=qu.front();
            qu.pop();

            int u=pr.first;
            int d=pr.second;

            if(d>distance[u])
            continue;

            for(auto adjv:adjl[u])
            {    int v=adjv.first;
                 int c=adjv.second;
                 if(distance[v]>(d+c))
                 {
                    distance[v]=d+c;
                    qu.push({v,distance[v]});
                 }
            }

        }

        int ans=0;

        for(int i=1;i<=n;i++)
        {
            if(distance[i]==INT_MAX)
            return -1;

            ans=max(ans,distance[i]);
        }

        return ans;
    }
};