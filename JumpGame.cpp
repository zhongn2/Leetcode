//JumpGame
// state: F[i] is it possible to move to ith position
// function: F[i] = F[j] plus is that possible to move from j to i
// initialization: F[0] = true; F[0,1,.....n] = false;
// answer: F[n-1]

class Solution {
public:
    bool canJump(int A[], int n) {
        bool f[n - 1];
        f[0] = true;
        for(int i = 1; i < n; i++){
            f[i] = false;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(f[j] && j + A[j] >= i){ // max length, which means the last step could more than the needed step, so here should be >=
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n-1];
    }
};