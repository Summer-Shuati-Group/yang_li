/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void invertHelper(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp; // swap left and right nodes
        invertHelper(root->left); 
        invertHelper(root->right); 
		// do this recursively for left and right subtree
    }    

    TreeNode* invertTree(TreeNode* root) {
        invertHelper(root);
        return root;
    }
};