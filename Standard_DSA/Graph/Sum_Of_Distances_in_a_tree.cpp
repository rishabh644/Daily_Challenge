class Solution {
public:
    vector<int>ans,count;
    vector<unordered_set<int>>graph;
    int N;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges)
    {
       this->N=N;

       graph.resize(N);
       ans.resize(N);
       count.resize(N,1);

       // Construct the graph

       for(auto& edge:edges)
       {
          graph[edge[0]].insert(edge[1]);
          graph[edge[1]].insert(edge[0]);
       }

       // First DFS to calculate counts and initial distances
      dfs(0,-1);

      // Second DFS to propaget the corrent distances to all nodes

      dfs2(0,-1);

      return ans;

    }


    void dfs(int node,int parent)
    {

       for(int child:graph[node])
       {
            if(child!=parent)
            {

                dfs(child,node);
                count[node]+=count[child];
                ans[node]+=ans[child]+count[child];

            }

       }


    }

   void dfs2(int node,int parent)
   {
         for(int child:graph[node])
         {
            if(child!=parent)
            {
                ans[child]=ans[node]-count[child]+N-count[child];
                dfs2(child,node);
            }

         }

   }



};


/////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges)
    {

       vector<vector<int>>adjl(N,vector<int>());

       for(int e=0;e<edges.size();e++)
       {

          adjl[edges[e][0]].push_back(edges[e][1]);
          adjl[edges[e][1]].push_back(edges[e][0]);

       }
       vector<int>ans(N,0);

       for(int i=0;i<N;i++)
       {

            dfs(i,-1,0,adjl,ans[i]);

       }

       return ans;

    }


    void dfs(int nd,int pr,int dep,vector<vector<int>>&adjl,int& dis)
    {
        dis+=dep;

        for(auto adjn:adjl[nd])
        {
            if(adjn!=pr)
            {
                dfs(adjn,nd,dep+1,adjl,dis);
            }
        }

    }




}
/////////////////----------------------/////////////------------------////////--------------