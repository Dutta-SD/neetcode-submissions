class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        return (-1+(int)sqrt(1 + 8 * grades.size()))/2;
    }
};