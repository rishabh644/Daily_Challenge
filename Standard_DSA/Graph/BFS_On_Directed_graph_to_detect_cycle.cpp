
    bool isCyclic(int V, vector<int> adj[]) {
        // code here

         vector<int>indegree(V,0);

         for(int i=0;i<V;i++)
         {
             for(auto adjv:adj[i])
             indegree[adjv]++;

         }

         queue<int>qu;

         vector<int>result;

         for(int i=0;i<V;i++)
         {
             if(indegree[i]==0)
             qu.push(i);
         }

         while(!qu.empty())
         {
            int v=qu.front();
            result.push_back(v);
            qu.pop();

            for(auto adjv:adj[v])
            {
                indegree[adjv]-=1;

                if(indegree[adjv]==0)
                qu.push(adjv);
            }


         }

         if(result.size()==V)
         return false;
         else
         return true;



    }