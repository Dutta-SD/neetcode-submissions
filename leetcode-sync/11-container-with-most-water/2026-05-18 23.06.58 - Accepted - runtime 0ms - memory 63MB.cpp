class Solution {
private:
    int area(vector<int>& heights, int l, int r) {
        return (r - l) * min(heights[l], heights[r]);
    }

public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int areaMax = -1;

        while (l < r) {
            areaMax = max(areaMax, area(heights, l, r));
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return areaMax;
    }
};