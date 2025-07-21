class Solution {
private:
     unordered_map<char,int>mp={{'F',1},{'W',2},{'E',3}};

     int Win(char me,char you)
     {

        // if( (me=='E' && you=='W') || (me=='W' && you=='F') || (me=='F' && you=='E'))
        // return 1;
        // else if( (me=='E' && you=='E') || (me=='W' && you=='W') || (me=='F' && you=='F'))
        // return 0;
        // else
        // return -1;
         if ((me == 'E' && you == 'E') || (me == 'W' && you == 'W') || (me == 'F' && you == 'F')) // draw
            return 0;
        else if ((me == 'E' && you == 'W') || (me == 'W' && you == 'F') || (me == 'F' && you == 'E')) // I win
            return 1;
        else
            return -1;

     }


public:

    int mod=1e9+7;
    vector<vector<vector<int>>>dp;
    int n;

    int solve(string &s,char last,int ind,int sum)
    {
        if(ind==n)
           return sum>=1;

        if(dp[ind][sum+n][mp[last]]!=-1)
        return dp[ind][sum+n][mp[last]];

        long long cnt=0;


        if (last != 'F') { // 1 -> F
            cnt = (cnt + solve(s, 'F', ind + 1, sum + Win('F', s[ind]))) % mod;
        }
        if (last != 'W') { // 2 -> W
            cnt = (cnt + solve(s, 'W', ind + 1, sum + Win('W', s[ind]))) % mod;
        }
        if (last != 'E') { // 3 -> E
            cnt = (cnt + solve(s, 'E', ind + 1, sum + Win('E', s[ind]))) % mod;
        }

        return dp[ind][sum + n][mp[last]] = cnt;

    }

    int countWinningSequences(string s)
    {
         n=s.size();
        dp.resize(n+1,vector<vector<int>>(2*n+1,vector<int>(4,-1)));

        return solve(s,'X',0,0)%mod;
    }


};