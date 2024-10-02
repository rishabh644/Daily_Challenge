class Solution {

    public:

    bool isbipartite(vector<vector<int>>&adjl)
    {
        int N=adjl.size();

        vector<vector<int>>vis(N,{0,0});
        queue<int>qu;

        for(int i=1;i<N;i++)
        {

        if(vis[i][0]==0)
        {
        qu.push(i);
        vis[i][0]=1;
        vis[i][1]=0;

        while(!qu.empty())
        {
           int v=qu.front();
           qu.pop();

           int cl=vis[v][1];

           for(auto adjv:adjl[v])
           {
              if(vis[adjv][0])
              {
                 if(vis[adjv][1]==cl)
                 return false;
              }
              else
              {
                qu.push(adjv);
                vis[adjv][0]=1;
                vis[adjv][1]=1-cl;
              }
           }

        }

        }

        }


        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        if(n==1)
        return true;

        vector<vector<int>>adjl(n+1,vector<int>());

        for(int i=0;i<dislikes.size();i++)
        {

            adjl[dislikes[i][0]].push_back(dislikes[i][1]);
            adjl[dislikes[i][1]].push_back(dislikes[i][0]);

        }


        if(isbipartite(adjl))
        return true;
        else
        return false;


    }
};