
class Solution {
private:
        unordered_map<char,int>ump;
public:
       Solution()
       {
        ump['a']=0;
        ump['e']=1;
        ump['i']=2;
        ump['o']=3;
        ump['u']=4;

       }


    int longestBeautifulSubstring(string w)
    {

      int n=w.size();
      int ans=0;

      auto wgt=[&](char c)
      {

        return ump[c];

      };



      auto checkAllVowelsPresent=[](vector<int>freq)
                                 {

                                   for(int i=0;i<5;i++)
                                   {
                                     if(freq[i]==0)
                                     return false;
                                   }

                                   return true;

                                 };

      auto checkNoRvrsOrd=[&](unordered_set<char>ust,char ch)
                    {
                        for(auto sch:ust)
                        {
                            if(wgt(sch)>wgt(ch))
                            return false;
                        }

                        return true;
                    };

      for(int i=0;i<n;i++)
      {

         vector<int>freq(5,0);
         unordered_set<char>ust;
         for(int j=i;j<n;j++)
         {

             freq[wgt(w[j])]+=1;


             if(checkAllVowelsPresent(freq) && checkNoRvrsOrd(ust,w[j]))
             {
                ans=max(ans,j-i+1);
             }

             if(!checkNoRvrsOrd(ust,w[j]))
             break;

             ust.insert(w[j]);


         }

      }

       return ans;

    }
};

// Above was in O(n^2)

class Solution {
  public:
    int longestBeautifulSubstring(string w)
    {
        int res=0;
        for(int i=0,j=0; i<w.size(); ++i)
        {
            if(w[i] == 'a')
            {
                int cnt=0;

                for(j=i+1; j<w.size() && w[j-1]<=w[j]; ++j)
                cnt+=w[j-1] < w[j];

                if(cnt==4)
                  res=max(res,j-i);

                i=j-1;
            }
        }
        return res;
    }
};
///
int longestBeautifulSubstring(string word)
    {
        int n=word.size(),pos=0,ans=0,count=0;
        char val;

        string vowel="aeiou";

        for(int i=0;i<n;i++)
        {

         val=word[i];

         if(pos!=0 && val==vowel[pos-1])
         {
            count+=1;
         }
         else if(pos<5 && val==vowel[pos])
         {
            count+=1;
            pos+=1;
         }
         else
         {
            pos=0;
            count=0;
            if(val=='a')
            {
                count=1;
                pos=1;
            }
         }

         if(pos==5)
         ans=max(ans,count);

        }

        return ans;
    }