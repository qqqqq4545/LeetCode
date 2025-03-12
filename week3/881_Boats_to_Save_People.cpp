class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the people by weight
        sort(people.begin(), people.end());
        
        int left = 0;              // Pointer to the lightest person
        int right = people.size() - 1;  // Pointer to the heaviest person
        int boats = 0;             // Counter for boats
        
        // Use two pointers approach
        while (left <= right) {
            // Try to pair the heaviest with the lightest
            if (people[left] + people[right] <= limit) {
                left++;    // Both people can fit in one boat
                right--;
            } else {
                right--;   // Only the heavier person can fit
            }
            boats++;       // Count this boat
        }
        
        return boats;
    }
};
