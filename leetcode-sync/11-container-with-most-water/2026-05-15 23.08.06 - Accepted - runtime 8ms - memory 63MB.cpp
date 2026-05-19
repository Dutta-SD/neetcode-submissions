class Solution {
private:
    int area(const vector<int>& height, int l, int r) {
        return min(height[l], height[r]) * (r - l);
    }

public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int aMax = area(height, l, r);

        while (l < r) {
            if (min(height[l], height[r]) == height[l]) {
                l++;
            } else
                r--;

            aMax = max(aMax, area(height, l, r));
        }

        return aMax;
    }
};