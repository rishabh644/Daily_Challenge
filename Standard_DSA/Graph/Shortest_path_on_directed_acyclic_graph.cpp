     void dfs(int V,vector< vector< pair<int,int> > >&adj_list,vector<vector<bool>>&visited,vector<int>&ans)
     {
        visited[V][0]=true;

        for(auto adj_v:adj_list[V])
        {
            int v=adj_v.first;

            if(!visited[v][0])
            {
                dfs(v,adj_list,visited,ans);
            }
        }

        ans.push_back(V);

     }

     vector<int> topological_sort(int N,vector< vector<pair<int,int>> >&adj_list)
     {
         vector<int>ans;

         vector<vector<bool>>visited(N,{false,false});

         for(int i=0;i<N;i++)
         {
             if(!visited[i][0])
             {
                 dfs(i,adj_list,visited,ans);
             }
         }

         reverse(ans.begin(),ans.end());

         return ans;

     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
     {
        // code here

        vector<int>ans;


        vector<vector<pair<int,int>>>adj_list(N);

        for(auto m:edges)
        {
            adj_list[m[0]].push_back({m[1],m[2]});
        }

        vector<int>tops=topological_sort(N,adj_list);

        vector<int>distance(N,INT_MAX);
        int src=0;
        distance[src]=0;

        for(auto v:tops)
        {
            if(distance[v]!=INT_MAX)
            {
                for(auto adj_v:adj_list[v])
                {
                    int ve=adj_v.first;
                    int wt=adj_v.second;

                    if(distance[ve]>(distance[v]+wt))
                    {
                        distance[ve]=distance[v]+wt;
                    }
                }
            }
        }

        for(int i=0;i<N;i++)
        {
            if(distance[i]==INT_MAX)
            distance[i]=-1;
        }

        return distance;

    }