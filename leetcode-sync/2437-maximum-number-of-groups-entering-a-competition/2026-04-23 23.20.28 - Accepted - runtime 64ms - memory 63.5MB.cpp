class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        priority_queue<int, vector<int>, greater<int>> pq(grades.begin(),
                                                          grades.end());

        int prevSum = 0;
        int prevNumElements = 0;
        int numGroups = 0;

        while (!pq.empty()) {
            int currSum = 0;
            int currNumElements = 0;

            while (!pq.empty() &&
                   (currSum <= prevSum || currNumElements <= prevNumElements)) {
                int e = pq.top();
                pq.pop();

                currSum += e;
                currNumElements++;
            }

            if (currSum <= prevSum || currNumElements <= prevNumElements)
                break;

            numGroups++;
            prevSum = currSum;
            prevNumElements = currNumElements;
        }

        return numGroups;
    }
};