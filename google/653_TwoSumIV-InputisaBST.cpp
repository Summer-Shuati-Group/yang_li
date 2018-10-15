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
    bool traversal(TreeNode* root, TreeNode* node, int target) {
        if (root == NULL) return false;
        if (root->val == target && root != node) return true;
        return (traversal(root->left, node, target) || traversal(root->right, node, target));
    }
    
    bool helper(TreeNode* root, TreeNode* node, int k) {
        if (node == NULL) return false;
        if (traversal(root, node, k - node->val)) return true;
        return (helper(root, node->left, k) || helper(root, node->right, k));
    }
    
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        return helper(root, root, k);
    }
};