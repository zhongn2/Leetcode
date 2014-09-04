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
        ListNode stdummy(-1);
        ListNode nddummy(-1);
        auto l = &stdummy;
        auto r = &nddummy;
        for(ListNode *curr = head;curr; curr = curr -> next){
            if(curr -> val < x){
                l -> next = curr;
                l = curr; // move the l pointer
            }else{
                r -> next = curr;
                r = curr;
            }
        }
        
        l -> next = nddummy.next;
        //nddummy.next = NULL;//stupid mistake. how can this happen??
		r -> next = NULL;
        return stdummy.next;
    }

};