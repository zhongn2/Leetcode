//we have two pointers, starts from begin and the other starts from end
// pseudo code as following:
// while( i < j){
// if(!isalnum(S[i]) i ++; continue;
// if(!isalnum(S[j]) j --; continue;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int i = 0, j = s.size() - 1;
        while( i < j){
            if(!isalnum(s[i])){
                i ++; continue;
            }
            if(!isalnum(s[j])){
                j --; continue;
            } // keep i and j at the same level
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            else{
                i ++;
                j --;
            }
        }
        return true;
    }
};