#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{

        int ans=0;
        int i,j;
        int n=s.size();

        unordered_map<char,int>ump;

        int last_repeat=-1;

        for(i=0;i<n;i++)
        {
             if(ump.find(s[i])!=ump.end())
             {
                last_repeat=max(last_repeat,ump[s[i]]);
             }
             ump[s[i]]=i;
             ans=max(ans,i-last_repeat);
             cout << ans << endl;
        }


        return ans;

}

int main()
{
    cout << lengthOfLongestSubstring("abba") << endl;
    return 0;
}