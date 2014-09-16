
// main idea: find the max of (j - i) * min(ai, aj)
class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1;
        int container = 0;
        while(i < j){
            container = max(container, (j - i) * min(height[i], height[j]));
            (height[i] > height[j])? j-- : i++;
        }
        return container;
    }
};