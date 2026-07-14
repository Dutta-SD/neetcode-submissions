class Solution {
    private static void swap(int a, int b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    private class UnionFind {
        private int[] parent, rank;

        public UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        public boolean union(int x, int y) {
            int rx = find(x);
            int ry = find(y);

            if (rx == ry)
                return false;
            if (rx >= ry)
                swap(rx, ry);
            // ry is always the parent
            parent[rx] = ry;
            rank[ry]++;
            return true;
        }

    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] ed = null;

        UnionFind uf = new UnionFind(n + 1);
        for (int[] e : edges) {
            if (!uf.union(e[0], e[1])) {
                ed = e;
            }
        }

        return ed;

    }
}