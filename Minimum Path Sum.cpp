//Minimum Path Sum

//f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]; 
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int path[m][n];
		//initialization
        path[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            path[i][0] = path[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < n; i++){
            path[0][i] = path[0][i - 1] + grid[0][i];
        }
		
        for(int i = 1; i < m; i++){
            for(int k = 1; k < n; k++){
                path[i][k] = min(path[i-1][k], path[i][k-1]) + grid[i][k];
            }
        }
        return path[m-1][n-1];
    }
};