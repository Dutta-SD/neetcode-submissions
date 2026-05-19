class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;
        
        while(i < j){
            int curr_area = (j - i) * min(height[i], height[j]);
            max_area = max(max_area, curr_area);
            height[i] < height[j] ? i++ : j--;
        }
        return max_area;        
    }
};