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
    ListNode *findMid(ListNode *head){
        if(head == NULL) return head;
        ListNode *slow = head,*fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
  ListNode *reverseList(ListNode *head){
        ListNode *prev = NULL;
        while(head != NULL){
            ListNode *tmp = head -> next;
            head -> next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
      
    
    void mergeList(ListNode *head, ListNode *tail){
        ListNode *dummy = new ListNode(-1);
        int index = 0;
        while(head && tail){
            if(index %2 == 0){
                dummy -> next = head;
                head = head -> next;
            }else{
                dummy -> next = tail;
                tail = tail -> next;
            }
            dummy = dummy -> next;// don't forget
            index ++;
        }
        if(head != NULL) 
            dummy -> next = head;
        if(tail != NULL)
            dummy -> next = tail;
    }
   
    
    void reorderList(ListNode *head) {
        if(head == NULL) return;
        ListNode *mid = findMid(head);
        ListNode *tail = reverseList(mid ->next);
        mid-> next = NULL; // break the head and tail
        mergeList(head, tail);
    }
};