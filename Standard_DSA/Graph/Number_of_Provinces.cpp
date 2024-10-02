class Solution {
public:

    void dfs(int v,vector<vector<int>>&adjl,vector<int>&visited)
    {
        visited[v]=1;

        for(auto adjv:adjl[v])
        {
            if(visited[adjv]==0)
            {
                dfs(adjv,adjl,visited);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n=isConnected.size();

        vector<vector<int>>adjl(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 if(isConnected[i][j])
                 {
                    adjl[i].push_back(j);
                 }

            }

        }

        int ans=0;

        vector<int>visited(n,0);

        for(int i=0;i<n;i++)
        {

            if(visited[i]==0)
            {
                dfs(i,adjl,visited);
                ans+=1;
            }

        }

        return ans;

    }

};