int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector< vector< pair<int,int> > >vp(n);

        for(const auto &f:flights) vp[f[0]].emplace_back(f[1],f[2]);

        priority_queue<ti,vector<ti>,greater<ti>>pq;

        pq.emplace(0,src,k+1);

        while(!pq.empty())
        {

            auto [cost,u,stops]=pq.top();
            pq.pop();
            if(u==dst) return cost;
            if(!stops) continue;

            for(auto to:vp[u]){
                auto [v,w]=to;
                pq.emplace(cost+w,v,stops-1);
            }


        }

        return -1;

    }

/////////////////////////////////////-------------------------------------///////////////////////////////////

void relax_edge(vector<int>&edge,vector<int>&curr,vector<int>&ans)
    {
        int s=edge[0];
        int d=edge[1];
        int cst=edge[2];

        if(curr[s]!=INT_MAX)
        {
            if(ans[d]==INT_MAX)
            {
                ans[d]=curr[s]+cst;
            }
            else if(ans[d]>(curr[s]+cst))
            {
                ans[d]=curr[s]+cst;
            }
        }

    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


        vector<int>ans(n,INT_MAX);
        vector<int>curr;

        int i=0;
        ans[src]=0;
        while(i<=k)
        {
            curr=ans;
            for(auto e:flights)
            {
                relax_edge(e,curr,ans);
            }


           i+=1;
        }

        return ans[dst]==INT_MAX?-1:ans[dst];

    }

///////////////////////////////////////////////////--------------------------------------------------------/////////////////////////////////////////////////////////