class Solution {
private:
    int dfs(int src,vector<vector<int>>&adjls,vector<int>&vis)
    {
        vis[src]=1;

        int ans=0;

        for(int adjv:adjls[src])
        {
            if(vis[adjv]==0)
            {
                ans=max(ans,1+dfs(adjv,adjls,vis));
            }
        }

        vis[src]=0;
        return ans;
    }

public:
    int treeDiameter(vector<vector<int>>& edges)
    {

        int n=edges.size();

        vector<vector<int>>adjls(n+1);

        vector<int>vis(n+1,0);

        for(auto e:edges)
        {

              adjls[e[0]].push_back(e[1]);
              adjls[e[1]].push_back(e[0]);
        }

        int ans=0;
        for(int v=0;v<n+1;v++)
        {
            if(adjls[v].size()==1)
            {
                ans=max(ans,dfs(v,adjls,vis));
            }
        }

        return ans;

    }
};