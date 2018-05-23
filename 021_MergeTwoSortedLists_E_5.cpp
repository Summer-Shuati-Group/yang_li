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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		/*
		Space: O(max(m, n)) where m and n refer to the size of two linked list respectively  
		Time: O(max(m, n)), where m and n refer to the size of two linked list respectively  

		Using the head + rest of linked list method to create the merged linked list
		*/
        if (l1 == NULL && l2 == NULL) return NULL;
        else if (l1 == NULL && l2 != NULL) return l2;
        else if (l1 != NULL && l2 == NULL) return l1;
		// determine whether both of l1 and l2 is empty or not 
		// return the non-empty one if there exists one
        ListNode* head = new ListNode((l1->val >= l2->val) ? l2->val : l1->val);
        ListNode* l3 = head;
        if (l1->val >= l2->val) l2 = l2->next;
        else l1 = l1->next;
		// set the head of the merged linked list 
		// and set the two pointers ready for looping
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                l3->next = new ListNode(l2->val);
                l2 = l2->next; 
            }
            else if (l2 == NULL) {
                l3->next = new ListNode(l1->val);
                l1 = l1->next;
            } // if either of two pointers is NULL, 
			// keep adding the non-empty pointers to the merged linked list
            else if (l1->val >= l2->val) {
                l3->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else if (l1->val < l2->val) {
                l3->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            l3 = l3->next;
        }
		l3->next = l1 ? l1 : l2;
        return head;



		/*
		Space: O(max(m, n)) where m and n refer to the size of two linked list respectively  
		Time: O(min(m, n)) where m and n refer to the size of two linked list respectively

		A much better solution would use a dummy head so that we do not
		need to set the head at the first but directly engage in looping part

		we do not need to iterate over the non-ending linked list but only attach to the 
		end of the merged linked list
		*/

		ListNode* head = new ListNode(INT_MAX); // set a dummy head at the very beginning 
        ListNode* l3 = head; // set l3 as iterative pointer
        while (l1 != NULL && l2 != NULL) {
            if (l1->val >= l2->val) {
                l3->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else if (l1->val < l2->val) {
                l3->next = new ListNode(l1->val);
                l1 = l1->next;
            }
			// whichever is bigger would be the next element in the merged linked list 
            l3 = l3->next;
        }
		// if one of the linked list reaches the end, 
		// then another list would have the rest of non-ending linked list
        l3->next = l1 ? l1 : l2;
        return head->next;
    }
};