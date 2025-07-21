class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {

        vector<vector<int>>adjl(n);

        vector<int>parent(n,-1);
        vector<bool>visited(n,0);

        queue<int>qu;


        for(int i=0;i<edges.size();i++)
        {

            adjl[edges[i][0]].push_back(edges[i][1]);
            adjl[edges[i][1]].push_back(edges[i][0]);

        }


        qu.push(0);
        visited[0]=true;





        while(!qu.empty())
        {
              int v=qu.front();
              int prt=parent[v];

              for(auto adjv:adjl[v])
              {

                 if(!visited[adjv])
                 {
                    visited[adjv]=true;
                    parent[adjv]=v;
                    qu.push(adjv);
                 }
                 else if(adjv!=prt)
                 {
                    return false;
                 }


              }

              qu.pop();
        }

        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            return false;
        }

        return true;

    }
};