/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
struct comparator
    {
        bool operator()(const ListNode *a, ListNode *b)
        {
            return a -> val > b -> val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        ListNode *dummy = new ListNode(-1);
        ListNode *node = dummy;
        
        priority_queue<ListNode*,vector<ListNode*>, comparator> prique;
        for(int i = 0; i < n; i++){
            if(lists[i])
                prique.push(lists[i]);
        }
        while(!prique.empty()){
            ListNode *small = prique.top();
            prique.pop();
            node -> next = small;
            node = node -> next;
            if(small -> next != NULL){ // small pointer is also in lists, when pop it, we need to push another node into the priority_queue
                prique.push(small -> next);
            }
        }
        return dummy->next;
    }
  
};
