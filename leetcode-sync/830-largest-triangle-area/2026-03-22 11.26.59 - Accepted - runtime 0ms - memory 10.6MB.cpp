#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
private:
    double area(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (double) abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]));
    }

public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = -1.0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++) {
                for(int k = j+1; k < points.size(); k++) {
                    maxArea = max(maxArea, area(points[i], points[j], points[k]));
                }
            }
        }

        return maxArea * 0.5; 
    }
};