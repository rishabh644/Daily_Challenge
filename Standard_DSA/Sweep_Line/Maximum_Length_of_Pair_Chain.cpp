bool Cmp(vector<int>&a,vector<int>&b)
{

    return a[1]<b[1];

}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {

        sort(pairs.begin(),pairs.end(),Cmp);

        int crend=pairs[0][1];
        int crchain=1;

        for(int i=1;i<pairs.size();i++)
        {
           if(crend<pairs[i][0])
           {
              crchain+=1;
              crend=pairs[i][1];
           }
        }

        return crchain;

    }
};
///////////////--------------------------///////////////////////////////
bool Cmp(vector<int>&a,vector<int>&b)
{

    return a[1]<b[1];

}

class Solution {
public:
    int longestPairChain(int i,vector<vector<int>>&pairs,int& n,vector<int>& memo)
    {
        if(memo[i]!=0)
        {
            return memo[i];
        }

        memo[i]=1;

        for(int j=i+1;j<n;j++)
        {
            if(pairs[i][1]<pairs[j][0])
            {
                memo[i]=max(memo[i],1+longestPairChain(j,pairs,n,memo));
            }
        }

        return memo[i];


    }

    int findLongestChain(vector<vector<int>>& pairs)
    {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());

        vector<int>memo(n);

        int ans=0;

        for(int i=0;i<n;i++)
        {
            ans=max(ans,longestPairChain(i,pairs,n,memo));
        }

        return ans;

    }
};
///////////////////////---------------------------/////////////////////////////////
class Solution {
public:


    int findLongestChain(vector<vector<int>>& pairs)
    {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());

        vector<int>dp(n,1);

        int ans=1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(pairs[i][1]<pairs[j][0])
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }

            }
            ans=max(ans,dp[i]);
        }



        return ans;

    }
};