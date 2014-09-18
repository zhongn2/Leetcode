/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 // node is the new node for the original node
 //画图来理解，这里需要一个hashmap来存数据，另一种方法是0（1)的space
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return head;
        unordered_map<RandomListNode *, RandomListNode *> map;//store的是newnode 和 original node 映射关系 
        RandomListNode *dummy = new RandomListNode(-1);
        RandomListNode *prev = dummy;
        RandomListNode *node;
        while(head != NULL){
            if(map.count(head) > 0){
                node = map[head]; // mapping to the random node
            }else{
                node = new RandomListNode(head -> label); //没有的话就设置
                map[head] = node; 
            }//intialize the map
            prev -> next = node;
            if(head -> random != NULL){
                if(map.count(head->random)){ //先判断指向的node是否在map里面
                    node->random = map[head->random]; // 把node的random指向和head一样的地方
                }else{
                    node->random = new RandomListNode(head->random->label);
                    map[head->random] = node->random;
                }
            }
            prev = node;
            head = head -> next;
            
        }
        return dummy ->next;
    }
};