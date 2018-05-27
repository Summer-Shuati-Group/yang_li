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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL;
        ListNode* prev = NULL;
      while (head != NULL) {
          temp = head; // set the current node as temp 
          head = head->next; // now generate the next node
          temp->next = prev; // current node's next node is prev node
          prev = temp; // prev node now becoems the current node
      }
        return temp;
    }
};