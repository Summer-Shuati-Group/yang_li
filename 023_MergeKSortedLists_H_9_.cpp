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
		// 1. declare a new ListNode pointer to store the merged 2 linked lists
		// however, this would cause MLE (Memory Limit Exceeded) at last


		// if (l1 == NULL && l2 == NULL) return NULL;
		// else if (l1 == NULL && l2 != NULL) return l2;
		// else if (l1 != NULL && l2 == NULL) return l1;
		// // determine whether both of l1 and l2 is empty or not 
		// // return the non-empty one if there exists one
		// ListNode* head = new ListNode((l1->val >= l2->val) ? l2->val : l1->val);
		// ListNode* l3 = head;
		// if (l1->val >= l2->val) l2 = l2->next;
		// else l1 = l1->next;
		// // set the head of the merged linked list 
		// // and set the two pointers ready for looping
		// while (l1 != NULL && l2 != NULL) {
		// // if either of two pointers is NULL, 
		// 	// // keep adding the non-empty pointers to the merged linked list
		// if (l1->val >= l2->val) {
		// l3->next = new ListNode(l2->val);
		// l2 = l2->next;
		// }
		// else if (l1->val < l2->val) {
		// l3->next = new ListNode(l1->val);
		// l1 = l1->next;
		// }
		// l3 = l3->next;
		// }
		// l3->next = l1 ? l1 : l2;
		// return head;



		// 2. Recursively trace l1 and l2, whichever is smaller is added to
		// the respective list, [Accepted]
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		/* Use mergeTwoSortedList Method (Brute Force) 
		Time: O(n^2), not efficient */
        if (lists.empty()) return NULL;
        for (int i = 0; i < lists.size() - 1; i++) {
            lists[i+1] = mergeTwoLists(lists[i], lists[i+1]);    
        }
        return lists[lists.size() - 1];


		
    }
};