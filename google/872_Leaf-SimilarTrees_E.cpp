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
    void traversal(TreeNode* root, vector<int>& v) {
        if (root != NULL && root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
        }
        if (root && root->left) traversal(root->left, v);
        if (root && root->right) traversal(root->right, v);
		// check the edge cases here is very important !!!
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1; vector<int> v2;
        traversal(root1, v1); traversal(root2, v2);
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
};