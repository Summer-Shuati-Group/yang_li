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
    int dfs(TreeNode* root, int cnt) {
        if (root == NULL) {
            return cnt;
        }
        cnt++;
        return max(dfs(root->left, cnt), dfs(root->right, cnt)); 
		// return the maximum depth of two subtrees 
    }
    
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};