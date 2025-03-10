```cpp
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        
        long long operations = 0;
        int prev = nums[n-1]; 
        
        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= prev) {
                prev = nums[i];
                continue;
            }
            
            // Calculate number of parts needed
            int parts = (nums[i] + prev - 1) / prev;
            
            // Add operations needed (parts - 1)
            operations += parts - 1;
            
            // Update previous value to the smallest part
            prev = nums[i] / parts;
        }
        
        return operations;
    }
};
```
