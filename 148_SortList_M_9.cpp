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
		// determine whether both of l1 and l2 is empty or not 
		// return the non-empty one if there exists one
        ListNode* head = new ListNode((l1->val >= l2->val) ? l2->val : l1->val);
        ListNode* l3 = head;
        if (l1->val >= l2->val) l2 = l2->next;
        else l1 = l1->next;
		// set the head of the merged linked list 
		// and set the two pointers ready for looping
        while (l1 != NULL && l2 != NULL) {
            // if either of two pointers is NULL, 
			// // keep adding the non-empty pointers to the merged linked list
            if (l1->val >= l2->val) {
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
    }

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
		ListNode *cur = head;
		while(l1 && l2){
			if(l1->val > l2->val){
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
			else{
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
		}
		cur->next = (l1 ? l1 : l2);
		while(cur->next) cur = cur->next;
		return cur;
	}
    
    ListNode* split(ListNode *head, int n){
		for(int i = 1; head && i < n; i++) head = head->next;
		// stopping condition: either reach the number of steps 
        // or reach the end of the linked list 
		if(!head) return NULL;
		ListNode *second = head->next;
		head->next = NULL; 
        // when head->next is set to NULL, merge function would stop at this condition
		return second;
	}
    
    ListNode* sortList(ListNode* head) {    
        // if (head == NULL || head->next == NULL) return head; // 0 or 1 element
        // ListNode* slow = head;
        // ListNode* fast = head;
        // ListNode* prev = NULL;
        // while (fast && fast->next) {
        //     prev = slow;
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // prev->next = NULL;
        // ListNode* l1 = sortList(head);
        // ListNode* l2 = sortList(slow);
        // return mergeTwoLists(l1, l2);
        
        
        
        
        
        

        if(!head || !(head->next)) return head;
        // if the linked list contains only 0 or 1 element,
        // then just return the head of linked list
		
		ListNode* cur = head;
		int length = 0;
		while(cur){
			length++;
			cur = cur->next;
		} //get the linked list's length
		
		ListNode dummy(0);
		dummy.next = head;
		ListNode *left, *right, *tail;
		for(int step = 1; step < length; step *= 2){
            // divide the linked list into segments by factor of 2 
            // first divide into segment of two, and sort these segements
            // then divide into segment of four, .......
			cur = dummy.next;
			tail = &dummy;
			while(cur){
				left = cur;
				right = split(left, step);
                // split locates the elements (step - 1) away 
                // so that right is 1 element away from left in this case
				cur = split(right,step);
                // split locates the elements (step - 1) away 
                // so that cur is 1 element away from right in this case 
                // cur is used to help locate left in the next iteration
				tail = merge(left, right, tail);
                // merge merges elements from left to right, ending with tail
                // if it hasn't reach the end of the list, then other sorted
                // segments would be followed the tail
			}
		}
		return dummy.next;
    }
};