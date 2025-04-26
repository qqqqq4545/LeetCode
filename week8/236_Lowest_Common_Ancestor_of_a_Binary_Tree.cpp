/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
        
        // If both nodes were found in different subtrees, current root is the LCA
        if (leftLCA && rightLCA) {
            return root;
        }
        
        // If both nodes are in the left subtree
        if (leftLCA) {
            return leftLCA;
        }
        
        // If both nodes are in the right subtree
        return rightLCA;
    }
};
