class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        
        if (deadendSet.count("0000")) return -1;
        
        if (target == "0000") return 0;
        
        queue<string> q;
        unordered_set<string> visited;
        
        q.push("0000");
        visited.insert("0000");
        int turns = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            turns++;
            
            for (int i = 0; i < levelSize; i++) {
                string current = q.front();
                q.pop();
                
                for (int j = 0; j < 4; j++) {
                    for (int direction = -1; direction <= 1; direction += 2) {
                        // Create a new combination by turning one wheel
                        string next = current;
                        // Turn the wheel (with wraparound)
                        char digit = current[j];
                        if (direction == -1) {
                            next[j] = (digit == '0') ? '9' : digit - 1;
                        } else {
                            next[j] = (digit == '9') ? '0' : digit + 1;
                        }
                        
                        // Check if we've reached the target
                        if (next == target) return turns;
                        
                        // Skip if it's a deadend or already visited
                        if (deadendSet.count(next) || visited.count(next)) continue;
                        
                        // Add to queue and mark as visited
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        
        return -1;
    }
};
