class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // If someone trusts another, their score decreases.
        // If someone is trusted, their score increases.
        vector<int> scores(n + 1, 0);
        
        for (auto& t : trust) {
            scores[t[0]]--; // Truster
            scores[t[1]]++; // Trustee
        }
        
        for (int i = 1; i <= n; i++) {
            // The judge is trusted by n-1 people and trusts 0 people.
            if (scores[i] == n - 1) return i;
        }
        
        return -1;
    }
};
