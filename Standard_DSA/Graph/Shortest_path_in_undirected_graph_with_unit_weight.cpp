class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>>adj_list(N);
        for(auto e:edges)
        {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

        vector<int>distance(N,-1);
        queue<int>qu;
        vector<bool>vis(N,false);
        qu.push(src);
        vis[src]=true;
        int dis=0;
        while(!qu.empty())
        {
           int sz=qu.size();

           int i=0;

           while(i<sz)
           {
               int v=qu.front();
               qu.pop();
               distance[v]=dis;

               for(auto adjv:adj_list[v])
               {
                   if(vis[adjv]==false)
                   {
                       vis[adjv]=true;
                       qu.push(adjv);
                   }
               }


               i+=1;
           }

            dis++;
        }

        return distance;

    }
};