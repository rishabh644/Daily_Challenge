class Solution {
public:
    void dfs(int v,vector<bool>&visited,vector<vector<int>>&adjlist)
    {
        visited[v]=true;

        for(auto adjv:adjlist[v])
        {

            if(!visited[adjv])
            {
                dfs(adjv,visited,adjlist);
            }


        }

    }
    int countComponents(int n, vector<vector<int>>& edges)
    {


       vector<bool>visited(n,false);

       vector<vector<int>>adjlist(n,vector<int>());

       for(int e=0;e<edges.size();e++)
       {

          adjlist[edges[e][0]].push_back(edges[e][1]);
          adjlist[edges[e][1]].push_back(edges[e][0]);

       }

       int cnct_cmpnt=0;

       for(int v=0;v<n;v++)
       {

           if(!visited[v])
           {
              dfs(v,visited,adjlist);
              cnct_cmpnt+=1;
           }

       }

       return cnct_cmpnt;

    }
};