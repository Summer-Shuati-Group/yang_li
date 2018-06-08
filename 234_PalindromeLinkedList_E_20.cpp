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
	ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next; // store the next listnode into a node named 'next'
            head->next=prev; // reverse: the next node is the originally previous one
            prev=head; // shift prev by one to become head 
            head=next; // shift head by one to become next
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
		/* Time: O(n) 
		Space: O(n) */
         vector<string> s;
        while (head) {
            s.push_back(to_string(head->val));
            head = head->next;
        }
        // cout << s << endl;
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;

		/* Time: O(n) 
		Space: O(1) */

		// reverse first half of the list 
		// compare each value of the reversed part with 
		// the second half of the list

        if (head == NULL) return true;
        ListNode* slow = head; // keep track of the current listnode
        ListNode* fast = head; // determine the half of the linked list
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        } // slow would be at the midpoint of the array 
        slow->next = reverseLinkedList(slow->next);
        slow = slow->next;
        while (slow) {
            if (slow->val != head->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};