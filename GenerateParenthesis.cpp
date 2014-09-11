// this is easy to think of recursion
// how we can do recursion??
// think about inner and outer part
// 1 and 2 consist of 3
// n = 1 ()
// n = 2 ()(), (())
// n = 3 ()()(), (())(),()(()), ((())), (()())


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n == 0) return vector<string> (1, "");
        if(n == 1) return vector<string> (1, "()");
        for(int i = 0; i < n; i++){
            for(auto inner : generateParenthesis(i))
                for(auto outer : generateParenthesis( n - 1 - i))
                    result.push_back("(" + inner + ")" + outer);
        }
        return result;
        
    }
};
