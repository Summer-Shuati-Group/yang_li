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
    int helper(TreeNode* root, int& sum) {
        if (root == NULL) return 0;
        int cur = root->val;
        int l = helper(root->left, sum);
        // max sum of left subtree
        int r = helper(root->right, sum);
        // max sum of right subtree
        int max_single = max(max(l, r) + cur, cur);
        // max of current node, current node + left subtree, current node + right subtree
        // must include current node, because 'max_single' calculates the max_sumBT
        int max_all = max(max_single, l + r + cur);
        // 'max_all' calculates the max_sum of every node below and including this node
        sum = max(sum, max_all);
        // update the sum if max_all >= sum 
        return max_single;
    }
    
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        helper(root, sum);
        return sum;
    }
};