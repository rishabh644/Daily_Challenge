class Solution {
public:
    bool is_same(string& temp,string& target)
    {
        if(temp.size()!=target.size())
        return false;

        int i=0;

        while(i<temp.size())
        {
            if(temp[i]!=target[i])
            return false;
            i+=1;
        }
        return true;
    }
    void all_subsequences(string &s,int i,string &temp,string &target,int &ans)
    {
        if(i==s.size())
        {
            if(is_same(temp,target))
            ans+=1;
            return;
        }

        //include
        temp.push_back(s[i]);
        all_subsequences(s,i+1,temp,target,ans);
        temp.pop_back();
        all_subsequences(s,i+1,temp,target,ans);
    }
    int numDistinct(string s, string t)
    {
        if(s.size()<t.size())
        return 0;

        string temp;
        int ans=0;
        all_subsequences(s,0,temp,t,ans);
        return ans;
    }
};
////////////////////////
class Solution {
public:

    long long numDistinct(string s, string t)
    {
        if(s.size()<t.size())
        return 0;

        int m=s.size();
        int n=t.size();

        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));

        for(int i=1;i<=n;i++)
        {
            dp[0][i]=0;
        }
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=1;
        }
        // dp[i][j] represent number of subsequence of s of length i equal
        // to number of subsequences of t of length j
        long long mod=1e9+7;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }
                else
                {
                    dp[i][j]=dp[i-1][j]%mod;
                }
            }

        }

        return dp[m][n];
    }
};
////////////////
class Solution {
public:

    long long numDistinct(string s, string t)
    {
        if(s.size()<t.size())
        return 0;

        int m=s.size();
        int n=t.size();

        vector<long long>prev(n+1,0);


        // dp[i][j] represent number of subsequence of s of length i equal
        // to number of subsequences of t of length j
        prev[0]=1;
        long long mod=1e9+7;

        for(int i=1;i<=m;i++)
        {
            vector<long long>curr(n+1,0);
            curr[0]=1;
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j]=(prev[j-1]+prev[j])%mod;
                }
                else
                {
                    curr[j]=prev[j];
                }

            }
            prev=curr;
        }

        return prev[n];
    }
};
///////////////////////////////////
class Solution {
public:

    int numDistinct(string s, string t)
    {
        if(s.size()<t.size())
        return 0;

        int m=s.size();
        int n=t.size();

        vector<int>prev(n+1,0);


        // dp[i][j] represent number of subsequence of s of length i equal
        // to number of subsequences of t of length j
        prev[0]=1;
        int mod=1e9+7;

        for(int i=1;i<=m;i++)
        {
            vector<int>curr(n+1,0);
            curr[0]=1;
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j]=(prev[j-1]+prev[j])%mod;
                }
                else
                {
                    curr[j]=prev[j];
                }

            }
            prev=curr;
        }

        return prev[n];
    }
};