class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> window;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove element that's outside the indexDiff window
            if (i > indexDiff) {
                window.erase(window.find((long long)nums[i - indexDiff - 1]));
            }
            
            long long current = (long long)nums[i];
            
            // Find the smallest element >= (current - valueDiff)
            auto it = window.lower_bound(current - valueDiff);
            
            if (it != window.end() && *it <= current + valueDiff) {
                return true;
            }
            
            window.insert(current);
        }
        
        return false;
    }
};
