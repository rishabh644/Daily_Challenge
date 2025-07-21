class Solution {
public:
    int longestCommonSubsequence(string t1, string t2)
    {
           int m=t1.size();
           int n=t2.size();

           vector<vector<int>>dp(m+1,vector<int>(n+1,0));

           for(int i=1;i<=m;i++)
           {

              for(int j=1;j<=n;j++)
              {

                  if(t1[i-1]==t2[j-1])
                  {
                     dp[i][j]=1+dp[i-1][j-1];
                  }
                  else
                  {
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                  }

              }

           }

           return dp[m][n];
    }
};
///////////////////////////////////////////////////
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2)
    {
           int m=t1.size();
           int n=t2.size();

           vector<int>prev(n+1,0);
           vector<int>cur(n+1,0);

           for(int i=1;i<=m;i++)
           {
              cur[0]=0;
              for(int j=1;j<=n;j++)
              {

                  if(t1[i-1]==t2[j-1])
                  {
                    cur[j]=1+prev[j-1];
                  }
                  else
                  {
                    cur[j]=max(prev[j],cur[j-1]);
                  }

              }
              prev=cur;

           }

           return prev[n];
    }
};
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minDistance(string w1, string w2)
    {

        int m=w1.size();
        int n=w2.size();

        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);

        for(int j=0;j<=n;j++)
        prev[j]=j;



        for(int i=1;i<=m;i++)
        {
            curr[0]=i;
            for(int j=1;j<=n;j++)
            {
                if(w1[i-1]==w2[j-1])
                {
                    curr[j]=prev[j-1];
                }
                else
                {
                    curr[j]=1+min(prev[j-1],min(prev[j],curr[j-1]));
                }
            }
            prev=curr;
        }

        return prev[n];




    }
};