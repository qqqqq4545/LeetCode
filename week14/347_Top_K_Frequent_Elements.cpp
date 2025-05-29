class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        vector<vector<int>> buckets(nums.size() + 1);
        
        for (auto& pair : freq) {
            int element = pair.first;
            int frequency = pair.second;
            buckets[frequency].push_back(element);
        }
        
        vector<int> result;
        
        // Start from the highest frequency bucket and work backwards
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            // Add all elements from current frequency bucket
            for (int element : buckets[i]) {
                result.push_back(element);
                if (result.size() == k) {
                    break;
                }
            }
        }
        
        return result;
    }
};

