class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        
        dp[0] = 0;
        
        for (int currentAmount = 1; currentAmount <= amount; currentAmount++) {
            for (int coin : coins) {
                // If the coin value is less than or equal to the current amount
                if (coin <= currentAmount) {
                    dp[currentAmount] = min(dp[currentAmount], 1 + dp[currentAmount - coin]);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
