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
        if (l1 == NULL && l2 == NULL) return NULL;
        else if (l1 == NULL && l2 != NULL) return l2;
        else if (l1 != NULL && l2 == NULL) return l1;
        ListNode* head = new ListNode((l1->val >= l2->val) ? l2->val : l1->val);
        ListNode* l3 = head;
        if (l1->val >= l2->val) l2 = l2->next;
        else l1 = l1->next;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                l3->next = new ListNode(l2->val);
                l2 = l2->next; 
            }
            else if (l2 == NULL) {
                l3->next = new ListNode(l1->val);
                l1 = l1->next;
            }
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
        return head;
    }
};