/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {f
		/*
		Space: one extra space to store the node->next for deletion
		Time: O(1)
		*/
        if (node->next == NULL) {
            delete node; 
        }
        else {
            swap(node->val, node->next->val);
            ListNode* temp = node->next;
            node->next = node->next->next; 
            delete temp;
        }

		
    }
};