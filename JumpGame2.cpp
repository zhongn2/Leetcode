// Jump Game 2
// state: F[i] from 0 to i, the least steps
//function: F[i] = min(F[j]) + 1, j < i && move j to i;
// initialization: F[0] = 0;
// answer: F[n-1]

class Solution {
public:
    int jump(int A[], int n) {
        int f[n];
        f[0] = 0;
        for(int i = 1; i < n; i++){
            f[i] = INT_MAX;
            for(int j = 0; j < i; j++){
                if(f[i] != INT_MAX && j + A[j] >= i){
                    f[i] = f[j] + 1;
                    break;
                }
            }
        }
        return f[n-1];
    }
};

//method2:
class Solution {
public:
    int jump(int A[], int n) {
       int step = 0;
       int last = 0; // the max distance can been reached
       int curr = 0; // the max distance that can be reached by using "ret +1" steps
       for(int i = 0; i < n; i++){
           if(i > last){
               last = curr;
               ++step;
           }
           curr = max(curr, i + A[i]);
       }
       return step;
    }
};