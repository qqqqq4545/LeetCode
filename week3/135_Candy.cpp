class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        // Initialize with 1 candy for each child
        vector<int> candies(n, 1);
        
        // First pass: left to right
        // Ensure right neighbor gets more candies if they have higher rating
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        
        // Second pass: right to left
        // Ensure left neighbor gets more candies if they have higher rating
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        
        // Sum up the total candies needed
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }
        
        return totalCandies;
    }
};
