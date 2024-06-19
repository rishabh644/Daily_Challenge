#include<iostream>
#include<vector>

using namespace std;

// Cn=Summation(0 to n-1)Ci*C(n-1-i)


unsigned long long catalan(int n){

    if(n==0)
        return 1;

    vector<unsigned long long> dp(n + 1, 0);

    dp[0] = 1;

    for (int = 1; i <= n;++i)
    {
        dp[i] = 0;
        for (int j = 0; j < i;++j){
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    return dp[n];
}