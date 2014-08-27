/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if(root == NULL) return;
        prev = first = second = NULL;
        inorderSearch(root);
        swap(first -> val, second -> val);
    }
private:
    TreeNode *prev, *first, *second;
    void inorderSearch(TreeNode *root){
        if(root -> left) inorderSearch(root -> left);
        if(prev != NULL){
            if(prev -> val > root -> val){
                if( first == NULL){
                    first = prev;
                }
                second = root;
            }
        }
        prev = root;
        if(root -> right) inorderSearch(root -> right);
    }
};