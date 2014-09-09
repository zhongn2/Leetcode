
//state: F[i] from 0 - i position the # of minimum cut
//function: f[i] = min(f[j] + 1 j < i && s[i , j] is palindrome)
// initialization: f[0] = 0
// answer: f[s.size()]
//here is another problem, check a string is palindrome is also time-comsuming
// so we will use another DP to solve that
// s[i][j] = s[i-1][j-1] i < j && s[i] == s[j]
// this problem turns out to be a double DP problem
class Solution {
public:
    int minCut(string s) {
       const int n = s.size();
       int f[n + 1];
       bool p[n][n];
       fill_n(&p[0][0], n * n, false);
       for(int i = 0; i <= n; i++){
           f[i] = n - 1 - i; // worst case each char is a cut
       }
       for(int i = n - 1; i >= 0; i--){
           for(int j = i; j < n; j++){
               if(s[i] == s[j] && (j -i < 2 ||p[i+1][j-1])){
                   p[i][j] = true;
                   f[i] = min(f[i], f[j+1] + 1);
               }
           }
       }
       return f[0];
     
    }
      
};