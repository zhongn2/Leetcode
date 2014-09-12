class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end()); // sort 
        vector<vector<int> > result; // final answer
        vector<int> path; // current path
        dfs(result, path, num); // depth first search
        return result;
    }
private:
    void dfs(vector<vector<int> > &result, vector<int> &path, vector<int> &num){
        if(path.size() == num.size()){ // find one path
            result.push_back(path);
            return;
        }
        for(auto i: num){
            auto pos = find(path.begin(), path.end(), i); // return the pos or the last
            if(pos == path.end()){
                path.push_back(i);
                dfs(result, path, num);
                path.pop_back();
            }
        }
        
    }
};