class Solution {
private:
   unordered_map<string,vector<string>>ump;

public:
   bool dfs(string a,string b,unordered_map<string,bool>&vis)
   {
          if(a==b)
          return true;

          if(vis[a])
          return false;

          vis[a]=true;

          for(auto adjs:ump[a])
          {
              if(dfs(adjs,b,vis))
              return true;
          }

         return false;
   }

    bool areSentencesSimilarTwo(vector<string>& s1, vector<string>& s2, vector<vector<string>>& sP)
    {

         int m=s1.size();
         int n=s2.size();

         for(auto v:sP)
         {
            ump[v[0]].push_back(v[1]);
            ump[v[1]].push_back(v[0]);
         }

         if(m!=n)
         return false;

         int i=0;
         int j=0;

         while(i<m && j<n)
         {
            unordered_map<string,bool>vis;
            if(!dfs(s1[i],s2[j],vis))
            return false;


            i+=1;
            j+=1;
         }

         return true;

    }
};
////////////////////
class Solution {
private:
   unordered_map<string,vector<string>>adj;

public:
   bool dfs(string& source,string& dest,unordered_set<string>&visit)
   {
          visit.insert(source);

          if(source==dest)
          return true;

          for(auto neighbor:adj[source])
          {
              if(!visit.count(neighbor) && dfs(neighbor,dest,visit))
              {
                return true;
              }

          }

         return false;
   }

    bool areSentencesSimilarTwo(vector<string>& s1, vector<string>& s2, vector<vector<string>>& sP)
    {

         int m=s1.size();
         int n=s2.size();

         for(auto v:sP)
         {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
         }

         if(m!=n)
         return false;

         int i=0;
         int j=0;

         while(i<m && j<n)
         {
            unordered_set<string>vis;
            if(!dfs(s1[i],s2[j],vis))
            return false;


            i+=1;
            j+=1;
         }

         return true;

    }
};
////////////////////////////
