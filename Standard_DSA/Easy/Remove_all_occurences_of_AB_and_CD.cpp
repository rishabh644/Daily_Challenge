class Solution {
public:
    bool remove(string& s)
    {
        string ans="";

        int i=0;
        bool allok=false;
        while(i<s.size())
        {
           if(s[i]=='A' && i+1<s.size() && s[i+1]=='B')
           {
            i+=2;
            allok=true;
            continue;
           }
           else if(s[i]=='C' && i+1<s.size() && s[i+1]=='D')
           {
              i+=2;
              allok=true;
              continue;
           }
           else
           {
            ans+=s[i];
            i+=1;
           }

        }

        s=ans;
        return allok;

    }
    int minLength(string s)
    {

        while(s.size()>0 && remove(s))
        {

        }
        return s.size();
    }
};
///////////////////////////////////
