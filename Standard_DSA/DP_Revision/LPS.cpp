class Solution {
public:
    string longestPalindrome(string s)
    {


        int n=s.size();

        vector<vector<bool>>dp(n,vector<bool>(n,false));

        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }

        int ans=1,indx=0;

        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<=(n-len);i++)
            {
                int j=i+len-1;

                if( s[i]==s[j] && (i+1>j-1 || dp[i+1][j-1] ) )
                {
                   dp[i][j]=true;
                   ans=len;
                   indx=i;
                }
            }
        }

        return s.substr(indx,ans);

    }
};
////////////////////////////
class Solution {
public:

    string expand(int i,int j,string s)
    {
        int left=i;
        int right=j;

        while(left>=0 && right<s.size() && s[left]==s[right])
        {
            left--;
            right++;
        }

        return s.substr(left+1,right-left-1);

    }

    string longestPalindrome(string s)
    {
       string ans="";

       for(int i=0;i<s.size();i++)
       {
          string odd=expand(i,i,s);
          if(odd.size()>ans.size())
          ans=odd;

          string even=expand(i,i+1,s);

          if(even.size()>ans.size())
          ans=even;

       }

       return ans;

    }
};