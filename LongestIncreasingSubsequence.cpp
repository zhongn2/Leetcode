// longest increasing subseqence 
//iven a sequence of integers, find the longest increasing subsequence (LIS).
//You code should return the length of the LIS.

public class Solution {
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    public int longestIncreasingSubsequence(int[] nums) {
        // write your code here
        for(int i = 0; i < nums.size(); i++){
            f[i] = 1;
        }
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] <= nums[i]){
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result = Math.max(result, f[i]);
        }
        return result;
    }
}

