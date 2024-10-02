class Solution {
public:
    void all_subsequences(int i,string& temp,string &s,unordered_set<string>&ust)
    {
        if(i==s.size())
        {
            if(temp.size()>0)
            {
               ust.insert(temp);
            }
            return;
        }

        // take
        temp=temp+s[i];
        all_subsequences(i+1,temp,s,ust);
        temp.pop_back();
        // don't take
        all_subsequences(i+1,temp,s,ust);

    }

    int distinctSubseqII(string s)
    {
         unordered_set<string>ust;
         int i=0;
         string temp="";
         all_subsequences(i,temp,s,ust);
         return ust.size();
    }
};