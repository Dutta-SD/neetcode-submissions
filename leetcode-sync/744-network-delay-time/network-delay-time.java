class Solution {
    record Pair(int node, int cost) {
    }

    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Pair>> adj = buildGraph(times, n);
        return djikstra(adj, k);
    }

    private List<List<Pair>> buildGraph(int[][] times, int numNodes) {
        List<List<Pair>> adj = new ArrayList<>(numNodes);

        for (int i = 0; i < numNodes; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : times) {
            // times[i] = (ui, vi, wi)
            int source = edge[0] - 1;
            int dest = edge[1] - 1;
            int cost = edge[2];

            adj.get(source).add(new Pair(dest, cost));
        }

        return adj;
    }

    private int djikstra(List<List<Pair>> adj, int k) {
        final int V = adj.size();
        final int[] distances = new int[V];
        Arrays.fill(distances, Integer.MAX_VALUE);
        final PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> Integer.compare(x.cost(), y.cost()));
        distances[k-1] = 0;

        pq.add(new Pair(k-1, 0));

        while (!pq.isEmpty()) {
            Pair cp = pq.remove();
            int currNode = cp.node();
            int currCost = cp.cost();

            if (currCost != distances[currNode])
                continue;

            for (Pair nbPair : adj.get(currNode)) {
                int nbNode = nbPair.node();
                int nbCost = nbPair.cost();
                if (currCost + nbCost < distances[nbNode]) {
                    distances[nbNode] = currCost + nbCost;
                    pq.add(new Pair(nbNode, currCost + nbCost));
                }
            }
        }
        return minimumNetworkDelayTime(distances, k);
    }

    private int minimumNetworkDelayTime(int[] distances, int k) {
        int maxDist = -1;
        System.out.println(Arrays.toString(distances));
        for (int d : distances) {
            if (d == Integer.MAX_VALUE) return -1;
            maxDist = Math.max(maxDist, d);
        }
        return maxDist;
    }
}