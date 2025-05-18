class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[i][j] = maximum number of floors (i eggs, j moves)
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
                
        int moves = 0;
        while (dp[k][moves] < n) {
            moves++;
            for (int eggs = 1; eggs <= k; eggs++) {
                dp[eggs][moves] = dp[eggs-1][moves-1] + dp[eggs][moves-1] + 1;
            }
        }
        
        return moves;
    }
};
