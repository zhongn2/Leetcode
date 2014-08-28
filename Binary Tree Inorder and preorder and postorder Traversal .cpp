
// recursion method.

class Solution {
public:
    void inorder(TreeNode *root, vector<int> & result){
        if(root != NULL){
        inorder(root->left, result);
        result.push_back(root -> val);
        inorder(root -> right, result);
        }
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};
// iteration method
// idea: inorder: left, root, right.
// we push all the left node into the stack the most left one at the top of the stack
// then pop it and go check the right side of the node
class Solution {
public:

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
       const TreeNode *p = root;
       stack<const TreeNode *> cache;
       while(p != NULL || !cache.empty()){
           if( p != NULL){
               cache.push(p);
               p = p -> left;
           }else{
               p = cache.top();
               cache.pop();
               result.push_back(p->val);
               p = p -> right;
           }
         }
         return result;
       }
};
// PREORDER TRAVERSAL
// an empty stack 
// do the following steps when the stack is not empty
// push root into the stack 
// push right child of popped item to the stack
// push left child of popped item to the stack

vector<int> preorderTraversal(TreeNode *root) {
       vector<int> result;
	   TreeNode *p = new TreeNode(-1);
	   stack<TreeNode *> myStack;
	   myStack.push(root);
	   while(!myStack.empty()){
			p = myStack.top();
			result.push_back(p -> val);
			myStack.pop();
			if(p -> right) myStack.push(p -> right);
			if( p -> left) myStack.push( p -> left);
		}
		return result;
	   }


// POSTORDER TRAVERSAL
// Two methods: 1. two stacks 2. one stack
// 1. create two stacks
// 2. push root to the first stack
// repeat the actions until first stack is empty
// 3. pop the root and push into second stack 
// 4. push the left and right children of popped item into the first stack
vector<int> postorderTraversal(TreeNode *root) {
	vector<int> result;
	if( root == NULL) return;
	stack<TreeNode *> myStack1;
	stack<TreeNode *> myStack2;
	myStack1.push(root);
	while(!myStack1.empty()){
		TreeNode *p = myStack1.top();
		result.push_back(p->val);
		myStack1.pop();
		myStack2.push(p);
		if( p -> right) myStack1.push(p -> right);
		if( p -> left) myStack1.push(p -> left);
	}
	std::reverse(result.begin(), result.end());
	return result;
	}
// one stack method
// push each node twice and compare each time the top of the stack and curr value

 vector postorderTraversal(TreeNode *root) {
	vector<int> result;
	if( root == NULL) return;
    stack<TreeNode *> myStack;
	myStack.push(root);
	myStack.push(root);
	while(!myStack.empty()){
		TreeNode *curr = myStack.top();
		myStack.pop();
		if(!myStack.empty() && curr -> val == myStack.top() -> val){
			if( curr -> right){
				myStack.push( curr -> right);
				myStack.push( curr -> right);
			}
			if(curr -> left){
				myStack.push( curr -> left);
				myStack.push( curr -> left);
			}
		}else{
			result.push_back(curr -> val);
		}
	}
	return result;		
}
        