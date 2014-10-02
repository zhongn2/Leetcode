public class Solution {
    public int largestRectangleArea(int[] height) {
        if(height.length == 0){
            return 0;
        }
        Stack<Integer> stack = new Stack<Integer>();//record the index of block
        int max = 0;
        for(int i = 0; i <= height.length; i++){
            int curr = (i == height.length) ? -1 : height[i];
            while(!stack.isEmpty() && curr <= height[stack.peek()]){
                int h = height[stack.pop()];
                int w = stack.isEmpty()? i : i - stack.peek() - 1;
                max = Math.max(max, h * w);
            }
            stack.push(i);
        }
        return max;
    }
}