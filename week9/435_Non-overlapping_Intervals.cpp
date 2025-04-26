class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort intervals by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 0;  // count of intervals to remove
        int end = intervals[0][1];  // end time of last selected interval
        
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval overlaps with previously selected interval
            if (intervals[i][0] < end) {
                count++;  // remove current interval
            } else {
                end = intervals[i][1];
            }
        }
        
        return count;
    }
};
