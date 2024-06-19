#define MOD 1000000007
class Solution
{

public:
    int countFriendsPairings(int n)
    {
        // code here

        vector<int>DP(n+1,0);

        DP[0]=1;
        // If there are no friends (i,e n=0), there are no ways to pair anyone up
        // because there are no individuals to work with. However, from a combinatorial
        // standpoint, the "empty set" is considered a valid way of doing nothing.

        DP[1]=1;

        for(int i=2;i<=n;i++)
        {
            DP[i]=(DP[i-1]%MOD+(i-1)*(1ll*DP[i-2]%MOD)%MOD)%MOD;
        }

        return DP[n];


    }
};