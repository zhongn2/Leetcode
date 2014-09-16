class Solution {
public:
    int trap(int A[], int n) {
        if(n < 2) return 0;
        int *left = new int[n];
        int *right = new int[n];
        // find the max height on the left for each state
        left[0] = 0;
        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1], A[i-1]);
        }
        // find the max height on the right
        right[n -1] = 0;
        for(int j = n - 2; j >= 0; j--){
            right[j] = max(right[j+1], A[j+1]);
        }
        int trapWater = 0;
        for(int i = 0; i < n; i++){
            if(min(left[i], right[i]) - A[i] > 0)
                trapWater += min(left[i], right[i]) - A[i];
        }
        delete left;
        delete right;
        return trapWater;
    }
};