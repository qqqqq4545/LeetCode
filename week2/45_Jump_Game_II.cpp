class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        // If array has only one element, no jumps needed
        if (n == 1) return 0;
        
        int jumps = 0;        // Count of jumps
        int currEnd = 0;      // Farthest position that can be reached with current number of jumps
        int currFarthest = 0; // Farthest position that can be reached with current number of jumps + 1
        
        for (int i = 0; i < n - 1; i++) {
            currFarthest = max(currFarthest, i + nums[i]);
            
            // If reached the end of the current jump range
            if (i == currEnd) {
                // Make another jump
                jumps++;
                // Update the end of the current jump range
                currEnd = currFarthest;
                
                // If already reach the last index, break
                if (currEnd >= n - 1) 
                break;
            }
        }
        
        return jumps;
    }
};