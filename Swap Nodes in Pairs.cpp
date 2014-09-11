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
    ListNode *swapPairs(ListNode *head) {
        if(!head) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy, *q = p -> next, *k = q -> next;
        for(;k (the same as k != NULL); p = q, q = q -> next k = q ? q -> next : NULL){ // overflow
            p -> next = k;
            q -> next = k -> next;
            k -> next = q;
        }
        return dummy.next;
    }
};
// for loop definition
// for( initialization; condition; increase);