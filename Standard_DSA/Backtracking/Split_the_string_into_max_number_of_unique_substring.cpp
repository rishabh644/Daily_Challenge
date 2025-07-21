class Solution {
private:
    int ans=0;
    unordered_set<string>ust;

    void my_maximal(string& s,int i,unordered_set<string>&ust)
    {

        if(i>=s.size())
        {
            ans=max(ans,int(ust.size()));
        }

        string temp="";

        for(int j=i;j<s.size();j++)
        {
            temp=temp+s[j];
            if(ust.find(temp)==ust.end())
            {
                ust.insert(temp);
                my_maximal(s,j+1,ust);
                ust.erase(temp);
            }

        }

    }



public:
    int maxUniqueSplit(string s)
    {
        my_maximal(s,0,ust);
        return ans;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
private:
    unordered_set<string>seen;

    int backtrack(string& s,int start)
    {

       if(start==s.size())
       return 0;

       int maxCount=0;


       for(int end=start+1;end<=s.size();++end)
       {

          string substring=s.substr(start,end-start);
          // If the substring is unique
          if(seen.find(substring)==seen.end())
          {
            seen.insert(substring);
            maxCount=max(maxCount,1+backtrack(s,end));
            seen.erase(substring);
          }

       }

       return maxCount;

    }



public:
    int maxUniqueSplit(string s)
    {


       return backtrack(s,0);

    }
};
