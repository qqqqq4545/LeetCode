class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort intervals by end point (ascending), and if end points are equal, 
        // sort by start point (descending)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        
        int n = intervals.size();
        int ans = 0;
        
        int largest = -1;
        int secondLargest = -1;
        
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            // Case 1: Neither of our two largest elements are in this interval
            if (start > largest) {
                // Pick the two largest elements from this interval
                ans += 2;
                largest = end;
                secondLargest = end - 1;
            }
            // Case 2: Only largest element is in this interval
            else if (start > secondLargest) {
                // Pick one more element (the largest possible)
                ans += 1;
                secondLargest = largest;
                largest = end;
            }
            // Case 3: Both largest and second largest elements are in this interval
            // No need to add more elements
        }
        
        return ans;
    }
};
