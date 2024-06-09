#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxprofit(vector<int>prices,int maxtransaction)
{
    int n = prices.size();

    vector<vector<int>> dp(maxtransaction+1, vector<int>(2, 0));
    vector<vector<int>> nextdp(maxtransaction + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0;i--)
    {
        for (int j = 1; j <= maxtransaction;j++)
        {   //stocks in hand
            dp[j][1] = max(nextdp[j][1], prices[i] + nextdp[j - 1][0]);
            //stocks not in hand
            dp[j][0] = max(nextdp[j][0], -prices[i] + nextdp[j][1]);
        }
        nextdp = dp;
    }

    return dp[maxtransaction][0];
}

int main()
{

}