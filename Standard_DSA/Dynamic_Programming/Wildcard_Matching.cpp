// int myMatch(int i,int j,string p,string s,vector<vector<int>>&dp)
    // {
    //     if(i<0 && j<0)
    //     return true;

    //     if(i<0 && j>=0)
    //     return false;

    //     if(j<0 && i>=0)
    //     {
    //         for(int ind=0;ind<=i;ind++)
    //         {
    //             if(p[ind]!='*')
    //             return false;
    //         }
    //         return true;
    //     }

    //     if(dp[i][j]!=-1)
    //     return dp[i][j];

    //     if(p[i]==s[j] || p[i]=='?')
    //     return dp[i][j]=myMatch(i-1,j-1,p,s,dp);

    //     if(p[i]=='*')
    //     return dp[i][j]=myMatch(i-1,j,p,s,dp) || myMatch(i,j-1,p,s,dp);

    //     return dp[i][j]=false;


    // }


///////////////////////////********************************************************//////////////////////////////////

// bool isMatch(string s, string p) {


//        int m=p.size();
//        int n=s.size();

//        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

//        //when length of p is 0 and length of s is 0

//        dp[0][0]=1;

//        // when length of p is zero and s length is >0
//        // it is false by default

//        // when length of s is zero and p length is not zero

//        for(int i=1;i<=m;i++)
//        {
//             if(p[i-1]=='*')
//            dp[i][0]=dp[i-1][0];

//        }

//        for(int i=1;i<=m;i++)
//        {

//           for(int j=1;j<=n;j++)
//           {

//             if(p[i-1]==s[j-1] || p[i-1]=='?')
//             {
//                 dp[i][j]=dp[i-1][j-1];
//             }
//             else if(p[i-1]=='*')
//             {
//                 dp[i][j]=dp[i-1][j] || dp[i][j-1];
//             }
//             else
//             {
//                 dp[i][j]=0;
//             }

//           }


//        }


//       return dp[m][n];




//     }

/////////////////////////////////////////////////*******************************************************************//////////////////////////////////////
    // bool isMatch(string s, string p) {

    //    int m=p.size();
    //    int n=s.size();

    //    vector<int>prev(n+1,0);
    //    vector<int>cur(n+1,0);

    //    prev[0]=1;

    //    for(int i=1;i<=m;i++)
    //    {
    //        cur[0]=0;

    //        if(p[i-1]=='*')
    //        {
    //           cur[0]=prev[0];
    //        }

    //        for(int j=1;j<=n;j++)
    //        {


    //         if(p[i-1]==s[j-1] || p[i-1]=='?')
    //         {
    //             cur[j]=prev[j-1];
    //         }
    //         else if(p[i-1]=='*')
    //         {
    //             cur[j]=prev[j] || cur[j-1];
    //         }
    //         else
    //         {
    //             cur[j]=0;
    //         }

    //        }

    //        prev=cur;


    //     }


    //   return prev[n];

    // }
/////////////////////////////////////////////////////////////////**************************************************************//////////////////////////////////////////////////////////////////////