class Solution {
    private enum NS {
        UNVISITED, VISITED, UNSAFE, SAFE
    }

    private NS[] nodeStates;

    private boolean isSafe(int[][] graph, int node) {
        if (nodeStates[node] == NS.VISITED)
            return false;
        if (nodeStates[node] == NS.UNSAFE)
            return false;
        if (nodeStates[node] == NS.SAFE)
            return true;

        nodeStates[node] = NS.VISITED;

        for (int nb : graph[node]) {
            if (!isSafe(graph, nb)) {
                nodeStates[node] = NS.UNSAFE;
                return false;
            }
        }

        nodeStates[node] = NS.SAFE;
        return true;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        final List<Integer> safeNodes = new ArrayList<>();
        nodeStates = new NS[graph.length];
        for (int node = 0; node < graph.length; node++) {
            nodeStates[node] = NS.UNVISITED;
        }

        for (int node = 0; node < graph.length; node++) {
            isSafe(graph, node);
        }

        for (int node = 0; node < graph.length; node++) {
            if (nodeStates[node] == NS.SAFE)
                safeNodes.add(node);
        }

        return safeNodes;
    }
}