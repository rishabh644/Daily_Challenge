#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1)
        return s;

        string ans = s.substr(0, 1);

        string even_i;
        string odd_i;

        for(int i=0;i<n;i++)
        {
               even_i=palindrome_length(s,i,i+1);
               odd_i=palindrome_length(s,i-1,i+1);
               cout << "i "<<i<<" even_i " << even_i<<" odd_i "<<odd_i << endl;

                ans=even_i.size()>odd_i.size()?(even_i.size()>ans.size()?even_i:ans):(odd_i.size()>ans.size()?odd_i:ans);

                //   if(even_i.size()>ans.size())
                //       ans = even_i;
                //  if(odd_i.size()>ans.size())
                //      ans = odd_i;
        }

        return ans;
    }
    private:
    string palindrome_length(string s,int l,int r)
    {
        while(l>=0 && r<s.size())
        {
            if(s[l]!=s[r])
                break;
            l--;
            r++;
        }
        return s.substr(l+1,(r-l-1));
    }
};

int main()
{

    Solution obj;
    string ss = "cbbd";
    cout << ss<< endl;
    cout<<obj.longestPalindrome("cbbd")<<endl;
    return 0;
}

// class Solution:
//     def longestPalindrome(self, s: str) -> str:
//         if len(s) <= 1:
//             return s

//         Max_Len=1
//         Max_Str=s[0]
//         dp = [[False for _ in range(len(s))] for _ in range(len(s))]
//         for i in range(len(s)):
//             dp[i][i] = True
//             for j in range(i):
//                 if s[j] == s[i] and (i-j <= 2 or dp[j+1][i-1]):
//                     dp[j][i] = True
//                     if i-j+1 > Max_Len:
//                         Max_Len = i-j+1
//                         Max_Str = s[j:i+1]
//         return Max_Str