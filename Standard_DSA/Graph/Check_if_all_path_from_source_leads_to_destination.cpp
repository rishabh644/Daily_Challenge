class Solution {
public:

    bool dfs(vector<vector<int>>&adjls,int v,int d,vector<int>&state)
    {
          if(state[v]==1)
          return false;

          if(state[v]==2)
          return true;


          if(adjls[v].empty())
          return v==d;

          state[v]=1; // Mark as visiting

          for(int adjv:adjls[v])
          {

              if(!dfs(adjls,adjv,d,state))
               return false;

          }

          state[v]=2; // Mark as visited and processed successfully
          return true;

    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination)
    {
         vector<vector<int>>adjls(n);

         for(auto e:edges)
         {
            adjls[e[0]].push_back(e[1]);
         }

         if(!adjls[destination].empty())
          return false;

         vector<int>state(n,0);

         return dfs(adjls,source,destination,state);
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:

    bool dfs(vector<vector<int>>&adjls,int v,int d,vector<bool>&vis,vector<bool>&inst)
    {

        if(vis[v]==true)
        return true;
        if(adjls[v].size()==0)
        {

            if(v==d)
            return true;
            else
            return false;

        }
        vis[v]=1;
        inst[v]=true;
        for(auto adjv:adjls[v])
        {
            if(inst[adjv] || dfs(adjls,adjv,d,vis,inst)==false)
            return false;

        }
        inst[v]=false;
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination)
    {
         vector<vector<int>>adjls(n);

         for(auto e:edges)
         {
            adjls[e[0]].push_back(e[1]);
         }

         if(adjls[destination].size()>0)
          return false;

         vector<bool>vis(n,false);
         vector<bool>inst(n,false);

         return dfs(adjls,source,destination,vis,inst);
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////