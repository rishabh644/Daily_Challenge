// There are a total of n tasks you have to pick, labelled from 0 to n-1.
// Some tasks may have prerequisite tasks, for example to pick task 0 you have
// to first finish tasks 1, which is expressed as a pair: [0, 1]
// Given the total number of n tasks and a list of prerequisite pairs of size m.
// Find a ordering of tasks you should pick to finish all tasks.
// Note: There may be multiple correct orders, you just need to return any one
// of them. If it is impossible to finish all tasks, return an empty array. Driver code will
// print "No Ordering Possible", on returning an empty array.
// Returning any correct order will give the output as 1, whereas any invalid order will give the output 0.

class Solution
{
  public:

    bool dfs(int V,vector<vector<int>>&adj_list,vector<vector<bool>>&vis,vector<int>&ans)
    {

        vis[V][0]=true;

        for(auto v:adj_list[V])
        {
            if(vis[v][0]==true)
            {
                if(vis[v][1]==false)
                return true;
            }
            else
            {
                if(dfs(v,adj_list,vis,ans))
                return true;
            }

        }

        vis[V][1]=true;
        ans.push_back(V);

        return false;
    }

    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
    {
        //code here

        vector<vector<int>>adj_list(n);

        for(auto m:prerequisites)
        {
            adj_list[m[1]].push_back(m[0]);
        }

        vector<int>ans;



        vector<vector<bool>>vis(n,{false,false});

        for(int v=0;v<n;v++)
        {
            if(vis[v][0]==false)
            {
                if(dfs(v,adj_list,vis,ans))
                {
                    //cout<<v<<" cycle detected "<<endl;
                    return {};
                }
            }

        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};