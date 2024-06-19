// We have N persons sitting on a round table.
// Any person can do a handshake with any other
// person.

//      1
// 2         3
//      4

// Handshake with 2-3 and 1-4 will cause cross.

// In how many ways these N people can make
// handshakes so that no two handshakes
// cross each other. N would be even.





    int count(int N){
        // code here


          int n=N/2;

          vector<int>dp(n+1,0);

          dp[0]=1;


          for(int i=1;i<=n;i++)
          {
              dp[i]=0;

              for(int j=0;j<i;j++)
              {
                  dp[i]+=dp[j]*dp[i-1-j];
              }
          }


          return dp[n];

}