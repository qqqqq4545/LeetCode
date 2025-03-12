class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int swaps = 0;
        
        // Create a mapping of person ID to their position in the row
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }
        
        for (int i = 0; i < n; i += 2) {
            int person = row[i];
            int partner = person % 2 == 0 ? person + 1 : person - 1;
            
            // If partner is not next to the current person
            if (row[i + 1] != partner) {
                // Find partner's position
                int partnerPos = pos[partner];
                
                // Swap the person at i+1 with the partner
                swap(row[i + 1], row[partnerPos]);
                
                // Update positions after swap
                pos[row[i + 1]] = i + 1;
                pos[row[partnerPos]] = partnerPos;
                
                swaps++;
            }
        }
        
        return swaps;
    }
};