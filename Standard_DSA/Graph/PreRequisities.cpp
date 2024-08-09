bool dfs(int V,vector<vector<int>>&adj,vector<vector<bool>>&vis)
    {
        vis[V][0]=true;


        for(auto v:adj[V])
        {

            if(vis[v][0]==true)
            {
                if(vis[v][1]==false)
                return true;
            }
            else
            {
                if(dfs(v,adj,vis))
                return true;
            }
        }



        vis[V][1]=true;

        return false;
    }

	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here

	    vector<vector<int>>adj(N);

	    for(auto m:prerequisites)
	    {
	        adj[m.second].push_back(m.first);
	    }


	    vector<vector<bool>>vis(N,{false,false});

	    for(int v=0;v<N;v++)
	    {
	        if(!vis[v][0])
	        {
	            if(dfs(v,adj,vis))
	            return false;
	        }
	    }

	    return true;

	}