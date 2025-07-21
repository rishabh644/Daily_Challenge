class Solution {
public:

    void dfs(int v,vector<vector<int>>&adjls,vector<int>&allver,unordered_set<int>&st)
    {

        st.insert(v);

        for(auto adjv:adjls[v])
        {
            if(st.find(adjv)==st.end())
            {
                allver.push_back(adjv);
                dfs(adjv,adjls,allver,st);
            }
        }

    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
    {

         int n=quiet.size();
         vector<int>ans(n,0);

         vector<vector<int>>adjls(n);

         for(auto e:richer)
         {
            adjls[e[1]].push_back(e[0]);
         }




         for(int v=0;v<n;v++)
         {
            vector<int>allver;
            unordered_set<int>st;


            dfs(v,adjls,allver,st);

            int mnqu=v;

            for(auto adjv:allver)
            {

               if(quiet[adjv]<quiet[mnqu])
               mnqu=adjv;

            }

            ans[v]=mnqu;

         }


         return ans;

    }
};
////////////////////////////////////
class Solution {
public:

    int dfs(int v,vector<vector<int>>&adjls,vector<int>&quiet,vector<int>&memo)
    {
        if(memo[v]!=-1)
        return memo[v];


        //Initially, the quietest person is the current person

        memo[v]=v;

        // traverse all neighbors and find the quietes person among all

        for(auto adjv:adjls[v])
        {
            int candidate=dfs(adjv,adjls,quiet,memo);
            if(quiet[candidate]<quiet[memo[v]])
            memo[v]=candidate;

        }

        return memo[v];

    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
    {

         int n=quiet.size();
         vector<int>ans(n,0);

         vector<vector<int>>adjls(n);

         for(auto e:richer)
         {
            adjls[e[1]].push_back(e[0]);
         }

          vector<int>memo(n,-1);

          for(int v=0;v<n;v++)
          {
            dfs(v,adjls,quiet,memo);
          }



         return memo;

    }
};