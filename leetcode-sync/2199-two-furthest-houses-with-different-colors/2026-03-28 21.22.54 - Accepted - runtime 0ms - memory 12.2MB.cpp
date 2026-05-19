class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i = 0;
        int j = colors.size() - 1;
        int maxDistance = -1;

        while (i < j) {
            if (colors[i] != colors[j]) {
                maxDistance = max(maxDistance, j - i);
                break;
            } else
                j--;
        }

        i = 0;
        j = colors.size() - 1;

        while (i < j) {
            if (colors[i] != colors[j]) {
                maxDistance = max(maxDistance, j - i);
                break;
            } else
                i++;
        }

        return maxDistance;
    }
};