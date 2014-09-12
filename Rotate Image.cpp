// Rotate 90 degree
// what about 180 degree?  
// 1 2 => 4 2 => 3 1
// 3 4 => 3 1 => 4 2
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n - i; j++)
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
       
        for(int i = 0; i < n / 2; i++)
            for(int j = 0; j < n; j++)
                swap(matrix[i][j], matrix[n -1 -i][j]);
    }
};