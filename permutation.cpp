Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

// 关键思想：第一个位置肯定用循环遍历一遍

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
		 // 这里查重的原因是因为无法改num的值，所以只能每次判断下加入的元素是否已经存在
            auto pos = find(path.begin(), path.end(), i); // return the pos or the last
            if(pos == path.end()){
                path.push_back(i);
                dfs(result, path, num);
                path.pop_back();
            }
        }
        
    }
};