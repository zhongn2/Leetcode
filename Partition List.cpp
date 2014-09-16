//Partition List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
  consider that find the nodes that are less than x -- first linked list
  all the elements are greater and equal to x -- second linked list
  point the 1st ->next to 2nd list
  return the 1st list
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL) return head;
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        ListNode *node1 = dummy1;
        ListNode *node2 = dummy2;
        while(head){
            if(head -> val < x){
                node1 -> next = head;
                node1 = node1 -> next;
            }else{
                node2 -> next = head;
                node2 = node2 -> next;
            }
            head = head -> next;
        }
        node2 -> next = NULL; // end flag
        node1 -> next = dummy2 -> next; // point dummy2 to the end of node1 list
        return dummy1 -> next;
    }
};