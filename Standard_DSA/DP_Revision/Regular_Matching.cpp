class Solution {
public:
    vector<vector<int>>dp;
    bool myMatch(string s,string p,int i,int j)
    {
        if (i == s.size() && j == p.size())
        {
            return true;
        }

        if (j == p.size()) {
            return false;
        }

        if (i == s.size()) {
            // Remaining pattern should all be of form "x*"
            while (j + 1 < p.size() && p[j + 1] == '*') {
                j += 2;
            }
            return j == p.size();
        }

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Match zero or more of p[j]
            return dp[i][j]=myMatch(s, p, i, j + 2) ||
                   ((s[i] == p[j] || p[j] == '.') && myMatch(s, p, i + 1, j));
        }

        if (s[i] == p[j] || p[j] == '.') {
            return dp[i][j]=myMatch(s, p, i + 1, j + 1);
        }

        return dp[i][j]=false;
    }

    bool isMatch(string s, string p)
    {
        dp=vector<vector<int>>(s.size(),vector<int>(p.size(),-1));
        return myMatch(s,p,0,0);
    }
};
////////////////////////////////////////////////////////-------------------------------------///////////////////////////////----------------------------///////////////////////////
class Solution {
public:
    bool isMatch(string s, string p)
    {

       if(p.size()==0)
       return s.size()==0;

       bool first_match=(s.size()>0 && (p[0]==s[0] || p[0]=='.'));

       if(p.size()>=2 && p[1]=='*')
       {
    return (isMatch(s,p.substr(2)) || (first_match && isMatch(s.substr(1),p)) );
       }
       else
       {
           return (first_match && isMatch(s.substr(1),p.substring(1)));
       }


    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
