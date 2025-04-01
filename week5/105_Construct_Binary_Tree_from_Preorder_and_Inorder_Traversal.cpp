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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }
    
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, 
                             vector<int>& inorder, int inStart, int inEnd,
                             unordered_map<int, int>& inorderMap) {
        // if processed all nodes
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        // The first element in preorder is the root of the current subtree
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find the position of the root in inorder traversal
        int rootIndexInorder = inorderMap[rootVal];
        
        // Number of elements in the left subtree
        int leftSubtreeSize = rootIndexInorder - inStart;
        
        // Recursively build the left subtree
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize,
                                    inorder, inStart, rootIndexInorder - 1, inorderMap);
        
        // Recursively build the right subtree
        root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                     inorder, rootIndexInorder + 1, inEnd, inorderMap);
        
        return root;
    }
};
