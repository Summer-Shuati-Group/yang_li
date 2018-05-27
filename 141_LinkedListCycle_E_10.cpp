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
    bool hasCycle(ListNode *head) {
		// 1. add a dummy head, if during the iterative process, 
		// we meet the dummy head, then we know it contains a cycle 
		// Time: O(n)
        if (head == NULL) return false;
        while (head) {
            if (head->val == INT_MIN) return true;
            ListNode* temp = head->next;
            ListNode* dummy = new ListNode(INT_MIN);
            head->next = dummy;
            dummy->next = temp;
            head = head->next->next;
        }
       return false;
	
		// 2. Hashtable: add ListNode into the hashtable, 
		// doing the iteration and check if the hashtable already 
		// contains the element
		unordered_set<ListNode*> s;
        while (head) {
            if (s.find(head) != s.end()) return true;
            s.insert(head);
            head = head->next;
        }
        return false;

		// 3. Two-pointers: 追逐问题 
		// left pointer would move 1 step while right pointer 
		// would move 2 steps. Therefore, if the linked list
		// contains a cycle, left would equal to right eventually
		// Time: O(n)
		if (head == NULL || head->next == NULL) return false;
        ListNode* left = head;
        ListNode* right = head->next;
        while (left != right) {
            if (right == NULL || right->next == NULL) {
                return false;
            }
            left = left->next;
            right = right->next->next;
        }
        return true;
    }
};