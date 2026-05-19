class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = 1, b;
        int minD = INT_MAX;

        while (w * w <= area) {
            int val = (area / w) - w;
            if (!(area % w) && val >= 0 && val < minD){
                minD = val;
                b = w;
            }
            w++;
        }

        return {area/b, b};
    }
};