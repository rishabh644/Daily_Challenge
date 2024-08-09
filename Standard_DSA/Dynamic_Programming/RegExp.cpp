class Solution {
public:

    int dfs(int i,int j,string& s,string& p,vector<vector<int>>&dp)
    {
         if( i>=s.size() && j>=p.size())
         return 1;
         else if( j>=p.size())
         return 0;

         bool match=false;

         match=i<s.size() && (s[i]==p[j] || p[j]=='.');

         if( (j+1)<p.size() && p[j+1]=='*')
         {
           return dp[i][j]=(dfs(i,j+2,s,p,dp) || (match && dfs(i+1,j,s,p,dp)));
         }

         if(match)
         {
           return dp[i][j]=dfs(i+1,j+1,s,p,dp);
         }

         return dp[i][j]=false;

    }

    bool isMatch(string s, string p)
    {

           int n=s.size();
           int m=p.size();

           vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

           return dfs(0,0,s,p,dp);
    }
};

// Note whenever there is * there is always a valid character before to check for match
