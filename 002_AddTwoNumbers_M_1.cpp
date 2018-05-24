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
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
        // write your code here
        addListsHelper(l1, l2);
        return l1;
    }
    
    void addListsHelper(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return;
        }
        else {
            l1->val += l2->val;
            if (l1->val >= 10) {
                if (l1->next) l1->next->val += 1;
                else l1->next = new ListNode(1);
                l1->val = l1->val % 10;
            }
            if (l1->next == NULL && l2->next != NULL) l1->next = new ListNode(0);
            else if (l2->next == NULL && l1->next != NULL)  l2->next = new ListNode(0);
            addListsHelper(l1->next, l2->next);
        }
    } 
};