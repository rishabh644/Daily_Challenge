class Solution {
private:
  unordered_map<char,vector<char>>adjList;
  bool topological_sort(string& ans)
  {

    unordered_map<char,int>ump_indegree;

    int num_c=0;

    for(auto ch:adjList)
    {

        vector<char>adjl=ch.second;
        for(auto adjv:adjl)
        {
            ump_indegree[adjv]++;
        }

        num_c++;
    }

    queue<char>qu;

    for(auto ch:adjList)
    {

        if(ump_indegree[ch.first]==0)
        {
             qu.push(ch.first);
        }

    }

    while(!qu.empty())
    {
        char ch=qu.front();
        ans+=ch;
        qu.pop();

        for(auto adjv:adjList[ch])
        {
            ump_indegree[adjv]-=1;

            if(ump_indegree[adjv]==0)
            {
               qu.push(adjv);
            }

        }

    }

    if(ans.size()!=num_c)
    return true;

    return false;

  }
public:
    string alienOrder(vector<string>& words)
    {

      // Step 0: Put all unique letters into reverseAdjList as keys.
       for(const string& word:words)
       {
          for(char c:word)
          {
                adjList[c]=vector<char>();
          }
       }
       for(int i=0;i<words.size()-1;i++)
       {
          const string& word1=words[i];
          const string& word2=words[i+1];
          // Check that word2 is not a prefix of word1.
          if(word1.length()>word2.length() && word1.substr(0,word2.length())==word2)
          {
            return "";
          }
          // Find the first non-match and insert the corresponding  relation
         for(int j=0;j<min(word1.size(),word2.size());j++)
         {
             if(word1[j]!=word2[j])
             {
                adjList[word1[j]].push_back(word2[j]);
                break;
             }
         }
       }
       // Step 2: DFS to build up the output list.
       string ans="";
       if(topological_sort(ans))
       {
           return "";
       }
       return ans;
    }

};
//////////////////////////
class Solution {
public:
    string alienOrder(vector<string>& words)
    {

        unordered_map<char,vector<char>>ump;

        unordered_map<char,int>indegree;

        string sta;
        string stb;

        unordered_set<char>ust;

        for(int i=0;i<words.size();i++)
        {
            sta=words[i];

            for(int j=i+1;j<words.size();j++)
            {

              stb=words[j];

              int lab=min(sta.size(),stb.size());
              int k=0;
              for( k=0;k<lab;k++)
              {

                if(sta[k]!=stb[k])
                {
                    ump[sta[k]].push_back(stb[k]);
                    indegree[stb[k]]+=1;
                    break;
                }

              }

              if(k==lab && k<sta.size() )
              return "";




            }

            for(char ch:sta)
            {
                ust.insert(ch);
            }

        }

        string ans;

        queue<char>qu;

        for( char ch:ust)
        {
            if(indegree[ch]==0)
            {
                qu.push(ch);
            }
        }

        while(!qu.empty())
        {
            char v=qu.front();
            ans=ans+v;

            for(auto adjv:ump[v])
            {
                indegree[adjv]-=1;

                if(indegree[adjv]==0)
                qu.push(adjv);
            }


            qu.pop();

        }

        if(ans.size()==ust.size())
        return ans;
        else
        return "";


    }
};