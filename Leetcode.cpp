1. pascal's Triangle

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> Pascal;
        if(numRows == 0) return Pascal;
        Pascal.push_back(vector<int>(1,1)); // first row 1
        
        for(int i = 2;i <= numRows; i ++){
            vector<int> curr(i, 1);// current line 1 1
            // every time generate 1 as first element and last element and change the 
            // from curr[1]
            vector<int> &prev = Pascal[i-2]; // the first line is P[0]
            for(int j = 1; j < i-1; j ++){
                curr[j] = prev[j-1] + prev[j];
            }
            Pascal.push_back(curr);
        } 
        return Pascal;
    }
};

// main idea:

vector<vector<int>> generate(int num){
 vector<vector<int>> res;
 if(num == 0) return res;
 res.push_back(vector<int>(1,1));
 for(int i = 2; i <= num; i ++){
	vector<int> current(i, 1); // no change about the first and last element
	vector<int> &prev = res[i-2];
	for(int j = 1; j < i -1; j ++){
		current[j] = prev[j-1] + prev[j];
		}
	res.push_back(current);
	}
	return res;
	}
	
 // Pascal's Triangle II 
 // 滚动数组，不断的覆盖之前写入的数据
 // 1 -》１　１　－》1 2 1 ->　1 3 3 1

 vector<int> getRow(int index){
	vector<int>row;
	for(int i = 0; i <index; i ++){
		for(int j = i -1; j > 0; j --){
			row[j] = row[j-1] + row[j]; 
		}
		row.push_back(1);
	}
	return row;
	
}

//Populating Next Right Pointers in Each Node II
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
       TreeLinkNode dummy(-1);
        for(TreeLinkNode *curr= root, *prev = &dummy; curr; curr = curr ->next){
            if(curr -> left){
                prev ->next = curr -> left;
                prev = prev -> next;
            }
              if(curr -> right){
                prev ->next = curr -> right;
                prev = prev -> next;
            }
            
        }
                
        connect(dummy.next);
            
        
      
    }
  
};


//Flatten Binary Tree to Linked List

public:
    void flatten(TreeNode *root) {
        flatten(root, NULL);
    }
private:
    TreeNode *flatten(TreeNode *root, TreeNode * tail){
        if(!root) return tail;
        root -> right = flatten(root->left, flatten(root->right, tail));
        root -> left = NULL;
        return root;
    }
	
	
//second solution

 void flatten(TreeNode *root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        // here the left and right are all flattened 
        if(root->left == NULL) return;
        TreeNode * p = root -> left;
        while(p->right){
            p = p -> right;
        }
        p->right = root -> right;
        root->right = root ->left;
        root -> left = NULL;
 
    }
	
	
	
// Path Sum II
 
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> >result;
        vector<int> current;
        pathsum(root, sum, result, current);
        return result;
    }
private:
    void pathsum(TreeNode *root, int sum, vector<vector<int> > &result, vector<int> &current){
        if(!root) return;
        current.push_back(root->val);
        if(root -> left == NULL && root -> right == NULL){
            if(sum == root->val)
                result.push_back(current);
        } 
        pathsum(root->left, sum - root->val, result, current);
        pathsum(root->right, sum - root->val, result, current);
        current.pop_back();
    }

};

//Minimum Depth of Binary Tree

class Solution {
public:
    int minDepth(TreeNode *root) {
     // the problem here could be that if one of the subtree(left/right is empty), we can't 
     // use the recusion. So it is necessary to introduce an boolean flag here
     return mindepth(root, false);
    }
    
    int mindepth(TreeNode *root, bool hasChild){
        if(!root) return hasChild ? INT_MAX:0;// return int_max means that the left/right side is empty
        return min(mindepth(root->left, root->right != NULL), mindepth(root->right, root->left != NULL)) + 1;
    }
};

//Balanced Binary Tree 
class Solution {
    // the main idea is to compare the depth of each subtree
    // if the diff is less than 1, then yes, either, no.
public:
    bool isBalanced(TreeNode *root) {
        return depth(root) >= 0;
    }
    
private:
    int depth(TreeNode *root){
        if(root == NULL) return 0;
        int ld = depth(root->left);
        int rd = depth(root->right);
        // use the oppsite way to think. 
        if(ld < 0 || rd < 0 || abs(ld-rd)> 1) return -1;
        return max(ld,rd) + 1;
    }
};


//Convert Sorted List to Binary Search Tree
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int length = 0; // record the length of linked list
        ListNode *p = head;
        while(p){
            length ++;
            p = p -> next;
        }
        // eg: 10 numbers the index is 0, 1,2,.....9
        return sort(head, 0, length - 1); 
    }

private:

    TreeNode *sort(ListNode* &head, int start, int end){
        if(end < start) return NULL;
        int mid = start + (end - start) /2;
        TreeNode *leftside = sort(head, start, mid-1);
        TreeNode *root = new TreeNode(head -> val);
        root -> left = leftside;
        head = head -> next;
        root -> right = sort(head, mid +1, end);
        
        return root;
    }
}

// Binary Tree Level Order Traversal II 
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        traverse(root, 1, result);
        reverse(result.begin(), result.end());
        return result;
    }
private:
    void traverse(TreeNode *root, int level, vector<vector<int> > &result){
        if(!root)return;
        // this means the tree only has root and push it into level 0
        if(level > result.size()) result.push_back(vector<int>());
        result[level-1].push_back(root->val); // push the root in
        traverse(root->left, level+1, result); // recursion
        traverse(root->right, level+1, result); // recursion
        
    }
};


//Symmetric Tree
class Solution {
  // why you always cant think about the solution
  // this should be done not just for once
  // i think I already done this for thousands of times
  // stupid bird in the world!
  // another solution comes with stack and compare each
  // each time, actually it is the same thought as the recursion one
  
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return issym(root->left, root->right);
    }
    bool issym(TreeNode *left, TreeNode *right){
        if(!left &&!right) return true;
        if(!left || !right) return false;
        return (left->val == right->val &&
        issym(left->left, right -> right) &&
        issym(left->right, right ->left));
        
    }
};


//Reverse Linked List II 
// need to figure out why this works
// swap element from m and n, count from m+1 and n-1. so when it comes to i, it goes with m+i and n-i;
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = head;
        for(int i = 0; i < n - m;  i++){
            int k1 = m+i;
            int k2 = n-i;
            if(k1 >= k2) return head;
            ListNode *p = head, *q = head;
            while(k1-1>0) {p = p ->next; k1--;}
            while(k2-1>0) {q = q ->next; k2--;}
            int tmp = p ->val;
            p->val = q->val;
            q->val = tmp;
        }
        return head;
    }
};



   void subsetDupHelper(vector<vector<int>> &result, vector<int> &S, vector::iterator start, vector<int> &path){
        result.push_back(path);
        for(vector::iterator i = start; i < S.end(); i++){
            if(i != start && *i == *(i-1)) continue;
            path.push_back(*i);
            subsetDupHelper(result, S, i+1, path);
            path.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
       vector<vector<int>>result;
       vector<int>path;
       subsetDupHelper(result, S, S.begin(),path);
    }
	
	
// need to be revised and try to make it accept
	  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	  sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path; // current solution
        combinationHelper(candidates, target, result, path, 0);
        return result;
    }
    void combinationHelper(vector<int> &cans, int gap, vector<vector<int>> &result, vector<int> &path, int start){
        if(gap == 0){
            result.push_back(path);
            return;
        }
        for(size_t i = start; i < cans.size(); i++){
            if(gap < cans[i]) return; // branchcut
            path.push_back(cans[i]);
            combinationHelper(cans, gap-cans[i], result, path, i); // recursion
            path.pop_back();
        }
		
		
// combination sum 2
		class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        vector<int> path;
        sumHelper(result, path, target,num, 0);
        return result;
    }
    void sumHelper(vector<vector<int>> &result, vector<int> &path, int gap, vector<int> &num, int start){
        if(gap == 0){
            result.push_back(path);
            return;
        }
        int p = -1; // previous num, make sure each one only is used for once
        for(size_t i = start; i < num.size(); i++){
            if(p == num[i]) continue; 
            p = num[i];
            if(gap < num[i]) return;
            path.push_back(num[i]);
            sumHelper(result, path, gap-num[i], num, i + 1);
            path.pop_back();
        }
    }
};



class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        combineHelper(result, path, 1, k, n, 0); // 从一开始
        return result;
    }
    void combineHelper(vector<vector<int>> &result, vector<int> &path, int start, int k, int n, int curr){ // current position: curr
        if(curr == k){ // reach the k
            result.push_back(path);
            return;
        }
        for(int i = start; i < n; i++){
            path.push_back(i);
            combineHelper(result, path, i, k, n, curr+1);
            path.pop_back();
        }
    }
};


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