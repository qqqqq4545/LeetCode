class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> candidate1, candidate2;
        
        // Check for a node with two parents
        for (int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                // v has two parents: parent[v] and u
                candidate1 = {parent[v], v};
                candidate2 = {u, v};
                // Mark this edge to be skipped temporarily
                edges[i][0] = edges[i][1] = -1;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        // Try to build the tree and check for cycles
        for (int i = 0; i < n; i++) {
            if (edges[i][0] == -1) continue; // Skip the marked edge
            
            int u = edges[i][0], v = edges[i][1];
            int rootU = find(parent, u);
            int rootV = find(parent, v);
            
            if (rootU == rootV) {
                if (candidate1.empty()) {
                    // No node with two parents, this edge creates a cycle
                    return edges[i];
                } else {
                    return candidate1;
                }
            }
            parent[rootV] = rootU;
        }
        
        return candidate2;
    }
    
private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};
