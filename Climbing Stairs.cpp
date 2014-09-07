
//simple DP questions
// state function F[i] = F[ i- 1] + F[i -2]; 
// i starts from 3
class Solution {
public:
    int climbStairs(int n) {
        int stairs[n];
        stairs[0] = 0;
        stairs[1] = 1;
        stairs[2] = 2;
        for(int i = 3; i <= n; i++){
            stairs[i] = stairs[i - 1] + stairs[ i - 2];
        }
        return stairs[n];
    }
};