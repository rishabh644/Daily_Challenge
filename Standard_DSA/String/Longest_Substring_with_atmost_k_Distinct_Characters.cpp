class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
       if(k==0)
       return 0;

       int l=0,r=0;

       int n=s.size();

       int count=0;

       int ans=0;

       unordered_map<char,int>ump;

       while(r<n)
       {
          if(ump.find(s[r])==ump.end())
          {
              count+=1;
              ump[s[r]]=1;
          }
          else
          {
            ump[s[r]]+=1;
          }
          while(l<r && count>k)
          {
            ump[s[l]]-=1;
            if(ump[s[l]]==0)
            {
                count-=1;
                ump.erase(s[l]);
            }
            l+=1;
          }

          ans=max(ans,r-l+1);
          r+=1;
       }

       return ans;
    }
};