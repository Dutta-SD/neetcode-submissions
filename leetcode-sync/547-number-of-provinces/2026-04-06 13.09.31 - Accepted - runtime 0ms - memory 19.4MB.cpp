class Solution {
    vector<int> parent;
    int components;

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression (makes it super fast)
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ; // Merge the two groups
            components--; // Two groups just became one
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        components = n;
        parent.resize(n);
        
        for (int i = 0; i < n; i++) parent[i] = i; // Everyone starts in their own group

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // Only need to check upper triangle
                if (isConnected[i][j] == 1) {
                    unite(i, j);
                }
            }
        }
        return components;
    }
};
