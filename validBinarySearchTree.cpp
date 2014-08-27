// vaild Binary Search Tree
// wrong idea":easily think that compare the left node with the root, and right node with the node.
// 10 5 15 6 20 -> 6 is less than 10. it is not a valid BST
// there are two bounds for each children. low and high
// keep track the bound in each recursion

class Solution {
public:
    bool isValidBST(TreeNode* root) {
       return ValidBSTHelper(root, INT_MIN, INT_MAX);
    }
    
    bool ValidBSTHelper(TreeNode *root, int low, int high){
        if(root == NULL) return true;
        if(low < root ->val && root -> val < high){
            return (ValidBSTHelper(root -> left, low, root -> val) && ValidBSTHelper(root -> right, root -> val, high));
        }
        return false;
    }
};
