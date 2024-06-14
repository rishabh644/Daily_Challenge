#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  int cutRod(int price[],int n) {

  // Create a DP array to store the maximum profit for each length

  vector<int> dp(n + 1, 0);

  // Build the DP array

  for (int i = 1; i <= n;i++)
  {

      int maxProfit = 0;

      for (int j = 1; j <= i;j++)
      {
          maxProfit = max(maxProfit, price[j - 1] + dp[i - j]);
      }

      dp[i] = maxProfit;
  }

  return dp[n];
                                }

}