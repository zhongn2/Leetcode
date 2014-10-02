
// O(n) complexicity
// we need a hashset to check that the consecutive element of each one is in the set or not
// so when we remove the consecutive elements in the set, to each element, they will be put into the set
// only once, the runtime complexicity is still O(n)


public class Solution {
    public int longestConsecutive(int[] num) {
        if(num.length == 0) return 0;
        int max = 1; 
        Set<Integer> set = new HashSet<Integer>();
        for(int n : num){
            set.add(n);
        }
        for(int number : num){
            int num1 = number + 1;
            int num2 = number - 1;
            int count = 1;
            while(set.contains(num1)){
                set.remove(num1);
                num1 ++;
                count ++;
            }
            while(set.contains(num2)){
                set.remove(num2);
                num2 --;
                count ++;
            }
            max = Math.max(max, count);
        }
      
        return max;
 
    }
}