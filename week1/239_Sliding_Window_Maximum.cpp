class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Store indices of potential maximum elements
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements outside current window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // Remove all elements smaller than current element from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Add current element's index to the deque
            dq.push_back(i);
            
            // Add the maximum element to result when we have a complete window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};