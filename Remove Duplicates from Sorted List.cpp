//Remove Duplicates from Sorted List 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return head;
        ListNode *node = head;
        while(node -> next){ // we need to compare with the next val, so here we should consider about the next node not node!!
            int v = node -> val;
            if(node -> next -> val == v){
                node -> next = node -> next -> next;
            }else{
                node = node -> next;
            }
        }
        return head;
    }
};

//Remove Duplicates from Sorted List ii

 class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head -> next == NULL) return head;
       ListNode *dummy = new ListNode(-1);
       dummy -> next = head; 
       ListNode *node = dummy;
       while(node -> next && node -> next -> next){
           if(node -> next -> next -> val == node -> next -> val){
                int v = node -> next -> val;
                while(node -> next && node -> next -> val == v){
                   node -> next = node -> next -> next;
               }
           }else{
               node = node -> next;
           }
       }
       return dummy -> next;
    }
};