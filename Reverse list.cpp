// reverse a linked list
// reverse a linked list. first thing we need to do is to store the value for the next node
// and then give previous node to the head next, then move head to the next level. meanwhile, prev will be the head compare with the tmp

void reverse(Node *&head){
	if(head == NULL) return;
	Node *prev = NULL;
	Node *tmp = NULL;
	while(head){
		tmp = head -> next;
		head -> next = prev;
		prev = head;
		head = tmp;
	}
	

//find the middle of the linked list
// we have two pointers and move one step by step, another one two steps each time
ListNode *findMid(ListNode *head){
	ListNode slow = head, fast = head -> next;
	while(fast != NULL && fast -> next != NULL){ // it has to be fast, it's fast than slow pointer
		fast = fast -> next -> next;
		slow = slow -> next;
	}
	return slow;
}



	 