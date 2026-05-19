class Solution {
private:
    vector<int> visited = vector<int>(26);

public:
    int residuePrefixes(string s) {
        int numResidues = 0;
        int numUnique = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!visited[s[i] - 'a']) {
                visited[s[i] - 'a'] = 1;
                numUnique++;
            }
            numResidues += (i + 1) % 3 == numUnique;
        }

        return numResidues;
    }
};