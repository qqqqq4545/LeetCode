class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]); // prereq[1] -> prereq[0]
        }
        
        vector<int> result;
        vector<int> visited(numCourses, 0); // 0: unvisited, 1: visiting, 2: visited
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(i, graph, visited, result)) {
                    return {}; // Cycle detected, impossible to finish all courses
                }
            }
        }
        
        // Reverse the result to get correct order
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    // Return true if cycle is detected
    bool hasCycle(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& result) {
        visited[node] = 1;
        
        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 1) {
                return true; // Cycle detected
            }
            if (visited[neighbor] == 0) {
                if (hasCycle(neighbor, graph, visited, result)) {
                    return true;
                }
            }
        }
        
        visited[node] = 2;
        result.push_back(node);
        return false;
    }
};
