// remove nth element in a linked list
//basic idea is to set two pointer and make the first one move n faster
// then delete the prev pointer to the next element
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
       // if(n <= 0) return NULL;
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *prev  = dummy;
        ListNode *after = head; // after is equal to head
        for(int i = 0; i < n; i++){
            after = after -> next;
        }
        while(after){ // reach the end should be itself, not the next pointer
            after = after -> next;
            prev = prev -> next;
        }// until after reach the end 
        ListNode *tmp = prev -> next; //before delete it, make a copy for it
        prev -> next = prev -> next -> next;
        delete tmp; // collect the garbage
        return dummy -> next;
        
    }
};