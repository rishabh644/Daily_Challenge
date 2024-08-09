// Check if word can be breaked into sentence from given dictionary

class Solution {
public:
    bool mywordBreak(string& s,int i,unordered_set<string>&ust,vector<int>&dp)
    {

        if(i>=s.size())
        return true;

        if(dp[i]!=-1)
        return dp[i]==1?true:false;

        for(int j=i;j<s.size();j++)
        {
            string subst=s.substr(i,j-i+1);

            if(ust.find(subst)!=ust.end())
            {
                if(mywordBreak(s,j+1,ust,dp))
                {
                    dp[i]=1;
                    return true;
                }
            }
        }
        dp[i]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
         int i=0;
         vector<int>dp(s.size(),-1);
         unordered_set<string>ust(wordDict.begin(),wordDict.end());

         return mywordBreak(s,i,ust,dp);
    }
};
//////////////////////
struct TrieNode
{
    bool isWord;
    unordered_map<char,TrieNode*>children;
    TrieNode():isWord(false),children(unordered_map<char,TrieNode*>()){}

};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
         TrieNode* root=new TrieNode();

         for(string word:wordDict)
         {
            TrieNode* curr=root;

            for(char c:word)
            {

               if(curr->children.find(c)==curr->children.end())
               {
                  curr->children[c]=new TrieNode();
               }

               curr=curr->children[c];
            }

            curr->isWord=true;

         }

         vector<bool>dp(s.size());

         for(int i=0;i<s.size();i++)
         {

              if(i==0 || dp[i-1])
              {

                TrieNode* curr=root;

                for(int j=i;j<s.size();j++)
                {

                    char c=s[j];
                    if(curr->children.find(c)==curr->children.end())
                    {
                        //No words exist
                        break;
                    }
                    curr=curr->children[c];

                    if(curr->isWord)
                    {
                        dp[j]=true;
                    }


                }



              }

          }


          return dp[s.size()-1];
    }



};