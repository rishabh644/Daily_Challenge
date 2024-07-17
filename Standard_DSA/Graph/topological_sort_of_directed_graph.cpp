void dfs(int i,vector<int>adj[],vector<bool>&vis,vector<int>&ans)
	{
	    vis[i]=true;

	    for(auto v:adj[i])
	    {
	       if(vis[v]==false)
	       dfs(v,adj,vis,ans);
	    }

	    ans.push_back(i);
	    return;
	}

	vector<int> topoSort(int V, vector<int> adj[])
	{
	    // code here

	    vector<int>ans;

	    vector<bool>visited(V,false);

	    for(int i=0;i<V;i++)
	    {

	        if(!visited[i])
	        {
	            dfs(i,adj,visited,ans);
	        }


	    }

	    reverse(ans.begin(),ans.end());

	    return ans;
	}