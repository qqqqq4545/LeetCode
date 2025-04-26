/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }
    
private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        
        // If the sum is negative, don't include that path (take 0 instead)
        int leftSum = max(0, maxPathSumHelper(node->left, maxSum));
        int rightSum = max(0, maxPathSumHelper(node->right, maxSum));
        
        // Update the global maximum sum if the current node forms a better path
        maxSum = max(maxSum, node->val + leftSum + rightSum);
        
        // Return the maximum sum of a path that starts at the current node
        // and goes down to either the left or right subtree (not both)
        return node->val + max(leftSum, rightSum);
    }
};
