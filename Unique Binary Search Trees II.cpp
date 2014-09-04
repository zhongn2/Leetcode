//Unique Binary Search Trees II
// recursion  generate the tree ( left, right) 
// the same way as the last question

//**
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
    vector<TreeNode *> generateTrees(int n) {
        if( n == 0) return generate(1, 0);
        return generate(1, n);
    }
    
    vector<TreeNode *>generate(int start, int end){
        vector<TreeNode *> result;
        if( start > end){
            result.push_back(NULL);
            return result;
        }
        for(int k = start; k <= end; k++){
            vector<TreeNode *> l = generate(start, k- 1);
            vector<TreeNode *> r = generate(k + 1, end);
            for(auto i : l){
                for(auto j : r){
                     TreeNode *subnode = new TreeNode(k);
                     subnode -> left = i;
                     subnode -> right = j;
                     result.push_back(subnode);
                }
            }
        }
        return result;
    }
};