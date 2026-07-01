class Solution {
    // 0 -> not visited; 1 -> in stack; 2 -> safe, 3 -> unsafe
    private int[] state;

    private boolean isSafe(int u, int[][] graph) {
        if (state[u] != 0) {
            return state[u] == 2;
        }

        state[u] = 1;

        for (int v : graph[u]) {
            if (state[v] == 1 || !isSafe(v, graph)) {
                state[v] = 3;
                return false;
            }
        }

        state[u] = 2;
        return true;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        final int N = graph.length;
        state = new int[N];

        for (int i = 0; i < N; i++) {
            isSafe(i, graph);
        }

        return IntStream.range(0, N)
                .filter(i -> state[i] == 2)
                .boxed()
                .toList();
    }
}