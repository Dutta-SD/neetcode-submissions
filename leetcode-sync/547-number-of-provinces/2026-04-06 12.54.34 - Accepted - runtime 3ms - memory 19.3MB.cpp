class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;
        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            // If there's a connection AND we haven't visited that neighbor yet
            if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++; // Found a new province!
                dfs(i, isConnected, visited); // Mark all cities in this province
            }
        }
        return provinces;
    }
};
