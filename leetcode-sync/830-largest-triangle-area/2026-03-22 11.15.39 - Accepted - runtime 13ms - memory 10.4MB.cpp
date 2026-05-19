class Solution {
private:
    double area(vector<int>& a, vector<int>& b, vector<int>& c) {
        return 0.5 * abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]));
    }

public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = -1.0;
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++) {
                for(int k = 0; k < points.size(); k++) {
                    maxArea = max(maxArea, area(points[i], points[j], points[k]));
                }
            }
        }

        return maxArea; 
    }
};