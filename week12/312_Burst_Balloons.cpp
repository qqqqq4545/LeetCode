class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> padded(n + 2, 1);
        for (int i = 0; i < n; i++) {
            padded[i + 1] = nums[i];
        }
        
        // dp[i][j] = maximum coins obtained by bursting all balloons between i and j
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int len = 1; len <= n; len++) {
            for (int left = 1; left <= n - len + 1; left++) {
                int right = left + len - 1;
                for (int last = left; last <= right; last++) {
                    int coins = padded[left - 1] * padded[last] * padded[right + 1];
                    // Add coins from bursting balloons in the left and right subarrays
                    coins += dp[left][last - 1] + dp[last + 1][right];
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }
        
        return dp[1][n];
    }
};
