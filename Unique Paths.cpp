//Unique Paths 
//p[i][j] is from[0][0] to i, j 
//p[i][j] = p[i-1][j] + p[i][j-1];
class Solution {
public:
    int uniquePaths(int m, int n) {
        int p[m][n];
         for(int i=0; i < m; i++){
            p[i][0] = 1;
        }
         for(int i=0; i < n; i++){
            p[0][i] = 1;
        } 
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                p[i][j] = p[i-1][j] + p[i][j-1];
            }
        }
        return p[m-1][n-1];
    }
};