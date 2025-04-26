iclass Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<int> count(n, 1);  // count[i] = number of nodes in subtree rooted at i (including i)
        vector<int> answer(n, 0); // answer[i] = sum of distances from node i to all other nodes
        
        // First DFS: Post-order traversal to compute count and partial answer
        dfs1(0, -1, count, answer, graph);
        
        // Second DFS: Pre-order traversal to compute final answer
        dfs2(0, -1, count, answer, graph, n);
        
        return answer;
    }
    
private:
    // First DFS: Calculate subtree sizes and distances from leaf to root
    void dfs1(int node, int parent, vector<int>& count, vector<int>& answer, vector<vector<int>>& graph) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs1(child, node, count, answer, graph);
                count[node] += count[child];
                answer[node] += answer[child] + count[child]; // Add child's answer plus the distances to all nodes in child's subtree
            }
        }
    }
    
    // Second DFS: Calculate final answers from root to leaf
    void dfs2(int node, int parent, vector<int>& count, vector<int>& answer, vector<vector<int>>& graph, int n) {
        for (int child : graph[node]) {
            if (child != parent) {
                // Re-root the tree: update answer when changing root from node to child
                // For node: we remove child's subtree (count[child]) and add the rest of the tree (n - count[child])
                answer[child] = answer[node] - count[child] + (n - count[child]);
                dfs2(child, node, count, answer, graph, n);
            }
        }
    }
};
