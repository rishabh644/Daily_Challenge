#include <vector>
#include <algorithm>
#include <climits>

int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    int count = 2; // Maximum number of transactions

    // Create a 3D DP table where dp[i][j][k] means the maximum profit at day i
    // with j transactions left and k is 1 if we have a stock in hand, else 0.
    std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(count + 1, std::vector<int>(2, 0)));

    // Base case initialization: No profit can be made if no transactions left or on day after last day
    for (int j = 0; j <= count; ++j) {
        dp[n][j][0] = dp[n][j][1] = 0;
    }
    for (int i = 0; i <= n; ++i) {
        dp[i][0][0] = dp[i][0][1] = 0;
    }

    // Bottom-up calculation
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j <= count; ++j) {
            dp[i][j][0] = std::max(dp[i + 1][j][0], -prices[i] + dp[i + 1][j][1]);
            dp[i][j][1] = std::max(dp[i + 1][j][1], prices[i] + dp[i + 1][j - 1][0]);
        }
    }

    // The result will be in dp[0][count][0] which means starting at day 0 with 'count' transactions left and not holding any stock
    return dp[0][count][0];
}

int main() {
    std::vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    std::cout << "Maximum Profit: " << maxProfit(prices) << std::endl;
    return 0;
}
