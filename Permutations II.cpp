// Permutations II
// method1: use hashmap to record and swap i with j( j = i .....n)

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size()== 0) return result;
        vector<int> path;
        dfs(result, path, num, 0);
        return result;
    }
    void dfs(vector<vector<int> > &result, vector<int> &path, vector<int> &num, int index){
        if(index == num.size()){
            result.push_back(path);
            return;
        }
        unordered_set<int> hashmap;
        for(int i = index; i < num.size(); i++){
            // the element is not in hashmap
            if(hashmap.find(num[i]) == hashmap.end()){
                hashmap.insert(num[i]);
                swap(num[index], num[i]);
                path.push_back(num[index]);
                dfs(result, path, num, index + 1);
                path.pop_back();
                swap(num[index], num[i]);
            }
        }
        
    }
};