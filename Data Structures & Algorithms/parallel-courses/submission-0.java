class Solution {
    public int minimumSemesters(int n, int[][] relations) {
        List<List<Integer>> adj = new ArrayList<>(n);
        int[] inDegrees = new int[n];
        int[] dist = new int[n];
        int md = 1;
        int nodesProcessed = 0;

        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
            dist[i] = 1;
        }

        for (int[] r : relations) {
            int source = r[0] - 1;
            int destination = r[1] - 1;
            adj.get(source).add(destination);
            inDegrees[destination]++;
        }

        Queue<Integer> queue = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            if (inDegrees[i] == 0) {
                queue.add(i);
            }
        }

        while (!queue.isEmpty()) {
            int node = queue.remove();
            nodesProcessed++;
            for (int nb : adj.get(node)) {
                --inDegrees[nb];
                dist[nb] = Math.max(dist[node] + 1, dist[nb]);
                md = Math.max(md, dist[nb]);
                if (inDegrees[nb] == 0)
                    queue.add(nb);
            }
        }

        if (nodesProcessed == n) {
            return md;
        }
        return -1;
    }
}
