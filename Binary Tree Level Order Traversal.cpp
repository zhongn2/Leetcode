
// Binary Tree Level Order Traversal
// used one queue to solve the problem
// datasture : vector<int> vector<vector<int>> queue<TreeNode*>
// bottom-up method could be reverse the result : std::reverse(result.begin(), result.end())

public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root) return result;
        
        queue<TreeNode *> curr; //store the current node 
        curr.push(root); //push root in
        // use two loops to handle current 
        while(!curr.empty()){
            vector<int> level; // store the value level by level
            int size = curr.size();
            for(int i = 0; i < size; i++){
                TreeNode *head = curr.front();
                curr.pop(); // the node needs to be popped, otherwise, it will be memory limit exceeded
                level.push_back(head -> val);
                if(head -> left) curr.push(head -> left);
                if(head -> right) curr.push(head -> right);
            }
             result.push_back(level);
        }
        return result;
    }
};