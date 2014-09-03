//Unique Binary Search Trees
// f(0) = 1 empty tree
// f(1) = 1 root
// f(2) = f(0) * f(1) // 1 as root
//		+ f(1) * f(0) // 2 as root
// f(3) = f(0) * f(2) // 1 as root
//		+ f(1) * f(1) // 2 s root
//		+ f(2) * f(0) // 3 as root
// ==> f(i) = sum(f(k - 1) * f(i - k)) ( k = 1 to i)

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1, 0);
        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int k = 1; k <= i; k++){
                f[i] += f[k - 1] * f[i - k];
            }
        }
        return f[n];
    }
};