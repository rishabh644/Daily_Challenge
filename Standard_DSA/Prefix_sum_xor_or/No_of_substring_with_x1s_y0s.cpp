#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int mod=1e9+7;

class Solution {
  public:
    int solve(int i,int p,int x,int y,int n,vector<vector<vector< vector<int> > >>&dp,string temp)
    {
        cout << temp << endl;

        if(i==n)
        {
            if(x==0 && y==0)
            {

                //cout<<temp<<endl;

                return 1;
            }
            else
            return 0;
        }

        if(x<0 || y<0)
        return 0;

        if( x>=0 && y>=0 && dp[i][p][x][y]!=-1)
        return dp[i][p][x][y];

        int ans=0;

        if(p==1)
        {
            if(y>0)
            ans=solve(i+1,0,x,y-1,n,dp,temp+"0");
            else
            return 0;
        }
        else
        {   if(x>0){
            ans=solve(i+1,1,x-1,y,n,dp,temp+"1");
                   }
            if(y>0){
                ans=ans+solve(i+1,0,x,y-1,n,dp,temp+"0");
            }
            ans=ans%mod;
        }

        cout << i << " " << ans << endl;
        return dp[i][p][x][y]=ans;

    }

    int CountString(int X, int Y) {
        // code here
        if(Y<(X-1))
        return 0;

        int n=(X+Y);



        vector<vector<vector< vector<int> > >>dp(n,vector< vector<vector<int>> >(2,vector<vector<int>>(X+1,vector<int>(Y+1,-1))));


        // start with 1

        int ans=0;



        ans=(solve(1,1,X-1,Y,n,dp,"1")+solve(1,0,X,Y-1,n,dp,"0"))%mod;

        return ans;


    }
};

int main()
{
    Solution obj;

   int count=obj.CountString(2, 2);

   cout << count << endl;

   return 0;
}