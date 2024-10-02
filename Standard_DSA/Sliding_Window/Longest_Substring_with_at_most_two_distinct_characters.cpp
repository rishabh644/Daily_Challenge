class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {


       int l=0;
       int h=0;

       unordered_map<char,int>ump;
       int ans=1;
       int count=0;
       while(h<s.size())
       {
           if(ump.find(s[h])==ump.end())
           {

               ump[s[h]]=1;
               count++;

           }
           else
           {
             ump[s[h]]+=1;
           }

           while(l<=h && count>2)
           {
              ump[s[l]]--;
              if(ump[s[l]]==0)
              {
               count-=1;
               ump.erase(s[l]);
              }
              l++;
           }

           ans=max(ans,h-l+1);
           //cout<<"h "<<" "<<h<<" "<<ans<<endl;
           h++;
       }

       return ans;


    }
};