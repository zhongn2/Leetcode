//Anagrams
//Given an array of strings, return all groups of strings that are anagrams.
//Note: All inputs will be in lower-case.
// the best way to do is to put all the anagram strings into map with the same key
// data structure here is a unordered_map 
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > strmap;
        // if there are anagrams words here, the origin string will be stored in the vector
        //next step is to printout
        for(const auto &s:strs){
            string key = s;
            sort(key.begin(), key.end());
            strmap[key].push_back(s);
        } 
        vector<string>result;
        for(auto it = strmap.cbegin(); it != strmap.cend(); it++){
            if(it -> second.size() > 1){
                //method1: result.insert(result.end(), it ->second.begin(), it ->second.end());
                copy(it->second.begin(), it -> second.end(), back_inserter(result));
            }
        }
        return result;
    }
};