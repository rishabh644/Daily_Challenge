class Solution {
public:
    string minRemoveToMakeValid(string s)
    {

       stack<int>indices;
       int len=s.size();
       unordered_set<int>ust;
       for(int i=0;i<len;i++)
       {

          if(s[i]=='(')
          indices.push(i);
          if(s[i]==')')
          {
             if(indices.empty())
             ust.insert(i);
             else
             indices.pop();

          }

       }

       while(!indices.empty())
       {
          ust.insert(indices.top());
          indices.pop();
       }

       stringstream ss;

       for(int i=0;i<len;i++)
       {
           if(ust.find(i)==ust.end())
           ss<<s[i];

       }

       string ans;
       ans=ss.str();

       return ans;

    }
};