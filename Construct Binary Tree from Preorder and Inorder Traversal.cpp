//Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int prelen = preorder.size();
        int inlen = inorder.size() - 1;
        if(prelen == 0 || inlen == 0) return NULL;
        return newTree(preorder, inorder, 0, inlen, 0);
    }
    TreeNode *newTree(vector<int> &preorder, vector<int> &inorder, int inst, int inend, int prest){
        if(inst > inend) return NULL;
        TreeNode *node = new TreeNode(preorder[prest]);
        int pos = -1;
        for(int i = 0; i <= inorder.size(); i++){
            if(inorder[i] == preorder[prest]){
                pos = i;
                break;
            }
        }
        node -> left = newTree(preorder, inorder, inst, pos -1, prest + 1); // the second root is prest + 1
        node -> right = newTree(preorder, inorder, pos + 1, inend, prest + 1 + pos - inst); // mid - inst is the size of left side
        return node;
    }
};