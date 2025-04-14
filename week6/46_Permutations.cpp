class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            // Swap the current position with the i-th element
            swap(nums[start], nums[i]);
            
            // Recursively generate permutations for the next position
            backtrack(nums, start + 1, result);
            
            // restore the array to its original state
            swap(nums[start], nums[i]);
        }
    }
};
