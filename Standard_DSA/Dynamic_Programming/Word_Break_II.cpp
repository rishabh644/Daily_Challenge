struct TrieNode
{
    bool isWord;
    unordered_map<char,TrieNode*>children;
    TrieNode():isWord(false),children(unordered_map<char,TrieNode*>()){}
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        TrieNode* root=new TrieNode;

        for(string word:wordDict)
        {
            TrieNode* curr=root;

            for(char c:word)
            {
                if(curr->children.find(c)==curr->children.end())
                {
                    curr->children[c]=new TrieNode;
                }
                curr=curr->children[c];
            }
            curr->isWord=true;
        }

        vector<vector<string>>dp(s.size(),vector<string>(0));

        for(int i=0;i<s.size();i++)
        {

              if(i==0 || dp[i-1].size()!=0)
              {

                  TrieNode* curr=root;
                  string temp="";

                  for(int j=i;j<s.size();j++)
                  {

                     char c=s[j];
                     temp+=c;
                     if(curr->children.find(c)==curr->children.end())
                     {
                        break;
                     }

                     curr=curr->children[c];
                      string si;
                     if(curr->isWord)
                     {
                           for(auto s:dp[i-1])
                           {
                            si=s+temp;
                            dp[i].push_back(si);
                           }
                     }
                  }
              }
        }
        return dp[s.size()-1];
    }


};