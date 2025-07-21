class Solution {
public:
    int maxRemovals(string s, string p, vector<int>& tI)
    {
        int sl=s.size();
        int pl=p.size();

        vector<int>cost(s.size(),0);

        for(int i=0;i<tI.size();i++)
        {
            cost[tI[i]]=1;
        }

        vector<vector<int>>dp(pl+1,vector<int>(sl+1,0));

        // dp[i][j]==minm cost for j length p from i length s

        int i,j;

        for(i=1;i<=pl;i++)
        {
            dp[i][0]=sl;
        }
        int nt,tk;
        for(i=1;i<=pl;i++)
        {

            for(j=1;j<=sl;j++)
            {

                 // not take
                  nt=dp[i][j-1];

                 // take
                 tk=sl;
                 if(p[i-1]==s[j-1])
                 {
                   tk=dp[i-1][j-1]+cost[j-1];
                 }

                 dp[i][j]=min(nt,tk);

            }

        }




        return tI.size()-dp[pl][sl];
    }
};