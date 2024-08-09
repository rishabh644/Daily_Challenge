class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
     int max=1e8;
    void relax_edge(vector<int>e,vector<int>&curr,vector<int>&ans)
    {
        int s=e[0];
        int d=e[1];
        int c=e[2];


        if(curr[s]!=max)
        {
            if(ans[d]==max)
            {
                ans[d]=curr[s]+c;
            }
            else if(ans[d]>(curr[s]+c))
            {
                ans[d]=curr[s]+c;
            }

        }



    }

    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S)
    {
        // Code here


        vector<int>ans(V,max);

        vector<int>curr;

        int cnt=1;
        ans[S]=0;
        while(cnt<=(V-1))
        {
            curr=ans;
            for(auto e:edges)
            {
                relax_edge(e,curr,ans);
            }

            cnt+=1;
        }

        curr=ans;
        for(auto e:edges)
        {
            if(curr[e[0]]!=max)
            {
                if(ans[e[1]]==max || ans[e[1]]>(curr[e[0]]+e[2]))
                {
                    return {-1};
                }
            }
        }

        return ans;

    }
};
