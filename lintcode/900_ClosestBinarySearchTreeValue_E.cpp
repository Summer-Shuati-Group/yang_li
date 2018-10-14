/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
     
     void traversal(TreeNode* root, double& target, double& cur) {
        if (root == NULL) {
            return;
        }
        traversal(root->left, target, cur);
        traversal(root->right, target, cur);
        if (abs(target - root->val) < abs(cur - target) ) {
            cur = root->val;
        }
    }
    
    int closestValue(TreeNode * root, double target) {
        // write your code here
        double val = root->val;
        traversal(root, target, val);
        return val;
    }
};