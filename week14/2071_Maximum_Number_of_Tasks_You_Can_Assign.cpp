class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int left = 0, right = min(tasks.size(), workers.size());
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canComplete(tasks, workers, pills, strength, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
private:
    bool canComplete(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        if (k == 0) return true;
        
        deque<int> availableWorkers(workers.begin(), workers.end());
        int pillsUsed = 0;
        
        for (int i = k - 1; i >= 0; i--) {
            int taskStrength = tasks[i];
            
            // Check if the strongest available worker can do this task without pill
            if (!availableWorkers.empty() && availableWorkers.back() >= taskStrength) {
                availableWorkers.pop_back();
            } else {
                if (pillsUsed >= pills) {
                    return false;
                }
                
                // Find the weakest worker who can do this task with a pill
                int neededStrength = taskStrength - strength;
                bool found = false;
                
                for (auto it = availableWorkers.begin(); it != availableWorkers.end(); ++it) {
                    if (*it >= neededStrength) {
                        availableWorkers.erase(it);
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    return false;
                }
                
                pillsUsed++;
            }
        }
        
        return true;
    }
};
