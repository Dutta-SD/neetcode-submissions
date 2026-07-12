class Solution {
    private static final int UNVISITED = 0;
    private static final int VISITED = 1;
    private static final int DONE = 2;
    private boolean hasCycle = false;

    private void dfs(
            int node,
            List<List<Integer>> adj,
            List<Integer> finalOrder,
            int[] nodeStatus) {
        if (nodeStatus[node] == VISITED) {
            hasCycle = true;
            return;
        }

        if (nodeStatus[node] == DONE) return;

        nodeStatus[node] = VISITED;

        for (int nb : adj.get(node)) {
            dfs(nb, adj, finalOrder, nodeStatus);
            if (hasCycle)
                return;
        }

        if (nodeStatus[node] != DONE) {
            finalOrder.add(node);
            nodeStatus[node] = DONE;
        }
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>(numCourses);
        List<Integer> finalOrder = new ArrayList<>();
        int[] nodeStatus = new int[numCourses];

        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : prerequisites) {
            int source = edge[1];
            int destination = edge[0];
            adj.get(source).add(destination);
        }

        for (int node = 0; node < numCourses; node++) {
            if (nodeStatus[node] == UNVISITED) {
                dfs(node, adj, finalOrder, nodeStatus);
            }
        }

        Collections.reverse(finalOrder);

        return !hasCycle
                ? finalOrder.stream().mapToInt(Integer::intValue).toArray()
                : new int[0];
    }
}