class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        add(digits, 1);
        return digits;
    }
    void add(vector<int> &digits, int d){
        int c = d;
        for(auto it = digits.rbegin(); it != digits.rend(); it++){
            *it += c;
             c = *it / 10;
             *it %= 10;
        }
        if(c > 0) digits.insert(digits.begin(), 1);
    }
};


// method2
// 12 + 1 simeple one
// 19 + 1 carry = 1
// 9 + 1 digit number needs change

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        int n = digits.size();
        
        for(int i = n - 1; i >= 0; i--){
            digits[i] += carry;
            if(digits[i] >= 10){
                digits[i] %= 10;
                carry = 1;
            }else{
                carry = 0;
                break;
            }
        }
        if(carry == 1){
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
        
    }
};