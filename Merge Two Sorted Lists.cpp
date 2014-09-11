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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        for(; l1 != NULL && l2 != NULL; p = p -> next){
            if(l1 -> val < l2 -> val){
                p -> next = l1;
                l1 = l1 -> next;
            }else{
                p -> next = l2;
                l2 = l2 -> next;
            }
        }
        // it is possible that one of the linked list is empty
        // we need to check which one is NULL
        p -> next = l2 == NULL? l1:l2;
        return dummy.next;
    }
};

// subtle method
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while(l1 && l2){
            if(l1 -> val > l2 ->val){
                p ->next = l2;
                l2 = l2 -> next;
            }else{
                p ->next = l1;
                l1 = l1 -> next;
            }
             p = p -> next;
        }
        p -> next = l1 == NULL? l2:l1;
        return dummy.next;
    }
};