class Solution {
public:
    bool bfs(int v,vector<bool>&visited,vector<vector<int>>&adjl)
    {
         pair<int,int>pr;

         pr={v,-1};

         queue<pair<int,int>>qu;
         qu.push(pr);

         visited[v]=true;

         while(!qu.empty())
         {
            pr=qu.front();
            qu.pop();
            int ve=pr.first;
            int prnt=pr.second;

            for(auto adjv:adjl[ve])
            {
                if(visited[adjv])
                {
                    if(adjv!=prnt)
                    return true;
                }
                else
                {
                    visited[adjv]=true;
                    qu.push({adjv,ve});
                }

            }

         }

         return false;

    }
    bool validTree(int n, vector<vector<int>>& edges)
    {

        vector<bool>visited(n,false);

        vector<vector<int>>adjl(n);

        for(auto e:edges)
        {
            adjl[e[0]].push_back(e[1]);
            adjl[e[1]].push_back(e[0]);
        }

        if(bfs(0,visited,adjl))
        return false;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            return false;
        }

        return true;

    }
};