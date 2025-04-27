class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        
        // dp[i]: minimum cost to paint i walls
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;  // Base case: no cost to paint 0 walls
        
        for (int i = 0; i < n; i++) {
            for (int j = n; j > 0; j--) {
                int previousWalls = max(0, j - time[i] - 1);
                dp[j] = min(dp[j], dp[previousWalls] + cost[i]);
            }
        }
        
        return dp[n];
    }
};
