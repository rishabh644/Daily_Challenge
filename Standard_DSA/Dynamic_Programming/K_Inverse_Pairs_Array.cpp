#include<iostream>
#include<bits/stdc++.h>

using namespace std;

public:

vector<vector<int>> dp;

int solve(int n,int k)
{
   if(k==0)
       return 1;
   if(n==0)
       return 0;

   if(dp[n][k]!=-1)
       return dp[n][k];

   int count = 0;

   for (int i = 0; i <= min(k, n - 1);i++){

       count = (count + solve(n - 1, k - i)) % mod;
    }

    return dp[n][k] = count;
}

int kInversePairs(int n,int k){
    dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
    return solve(n, k);
}



///////////-------------------////////////////////

vector<vector<in>> dp;

int kInversePairs(int N,int K)
{

    dp = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));

    for (int n = 1; n <= N;n++)
    {
        for (int k = 0; k <= K;k++)
        {
           if(k==0){

               dp[n][k] = 1;
               continue;

                   }
                   for (int i = 0; i <= min(k, n - 1);i++)
                   {
                       dp[n][k] = (dp[n][k] + dp[n - 1][k - i]) % mod;
                   }
        }
    }

    return dp[N][K];
}
/////////////////////------------------/////////////////
class Solution {
public:
    vector<vector<int>>dp;
    int mod=1000000007;
    int kInversePairs(int N, int K) {
    dp = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));
    dp[0][0]=1;
    for (int n = 1; n <= N;n++)
    {
        for (int k = 0; k <= K;k++)
        {
           if(k==0){
               dp[n][k] = 1;
               continue;
                   }
           dp[n][k]=(dp[n-1][k]+dp[n][k-1])%mod;

           if(k>=n)
           {
            dp[n][k]=(dp[n][k]+mod-dp[n-1][k-n])%mod;
           }

        }

    }

    return dp[N][K];


    }
};
//  Have a dr run