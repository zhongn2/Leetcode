// idea is that compare A and B element
// put the smaller one into A
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index = m + n; // index to be used in-place
        while(m > 0 && n > 0){
            if(A[m - 1] > B[n - 1]){
                // A is bigger, put A at the end
                // move m to m - 1
                A[--index] = A[--m];
            }
            else{ // the same to B
                A[--index] = B[--n];
            }
        }
        // we need to consider that two situations:
        //1. A is longer than B. since A is sorted, we dont need to change anything,
        //   that's why we start from the end, not the begin
        //2. B is longer than A. we need to move the rest of B into A
        while( n > 0){
            A[--index] = B[--n];
        }
    }
};