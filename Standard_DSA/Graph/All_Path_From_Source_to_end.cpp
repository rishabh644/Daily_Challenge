class Solution {
public:
    void dfs(int ver,vector<vector<int>>& graph,vector<vector<int>>&ans,vector<int>&temp)
    {
        temp.push_back(ver);

        if(ver==graph.size()-1)
        {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        for(auto adjv:graph[ver])
        {
            dfs(adjv,graph,ans,temp);
        }

        temp.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>>ans;

        vector<int>temp;

        dfs(0,graph,ans,temp);

        return ans;
    }
};