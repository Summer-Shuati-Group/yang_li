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
    bool isSameTree(TreeNode* p, TreeNode* q) {
		
		// one way of writing this

        if (p == NULL && q == NULL) {
            return true;
        } // reaches the end of both subtrees, return true
        if (p != NULL && q != NULL) {
            if (p->val != q->val) return false;
        } // if there exists a discrepancy in the values, return false
        if (p != NULL &&  q == NULL || p == NULL && q != NULL) {
            return false;
        } // if any of these two subtrees are null, return false
        bool l = isSameTree(p->left, q->left); // go through the left subtree
        bool r = isSameTree(p->right, q->right); // go through the right subtree
        return l && r; // combined are the result 



		// another way of writing this
		if (p == NULL || q == NULL) {
            return p == q;
        } 
		// three cases: 
		// 		1. p == NULL, q != NULL: return false (different pointers)
		// 		2. p != NULL, q == NULL: return false (different pointers) 
		//		3. p == NULL, q == NULL: return true 
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};