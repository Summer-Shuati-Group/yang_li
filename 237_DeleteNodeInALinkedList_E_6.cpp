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
		Two Methods: 
		1. 
			if node->next != NULL, swap node and node->next and delete node->next
			else just delete node->next
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

		/*
		2. 
			create a dummy pointer after the node, swap node and dummy and delete the node
		
		Both of these methods could run in constant time
		*/
        ListNode dummy(0);
        dummy.next = node->next;
        swap (*node, *(node->next));
        delete dummy.next;

    }
};