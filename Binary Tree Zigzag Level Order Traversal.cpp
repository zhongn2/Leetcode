// set a boolean flag to control the order


class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root) return result;
        
        queue<TreeNode *> curr;
        vector<int> level;
        bool ordered = true;
        curr.push(root);
        curr.push(NULL); // NULL seperator between levels
        
        while(!curr.empty()){
            TreeNode *head = curr.front();
            curr.pop();
            if(head){
                level.push_back(head ->val);
                if(head -> left) curr.push(head -> left);
                if(head -> right) curr.push(head -> right);
            }else{ // decide the order
                if(ordered){
                    result.push_back(level);
                }else{
                    reverse(level.begin(), level.end());
                    result.push_back(level);
                }
                level.clear();
                ordered = ! ordered;
                if(curr.size() > 0) curr.push(NULL);
            }
        }
        
    return result;
       
    }
};