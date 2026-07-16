class Solution {
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

        public boolean hasSameParent(int x, int y) {
            return find(x) == find(y);
        }

        public boolean union(int x, int y) {
            int rx = find(x);
            int ry = find(y);

            if (rx == ry)
                return false;

            if (rank[rx] >= rank[ry]) {
                rx = rx ^ ry;
                ry = rx ^ ry;
                rx = rx ^ ry;
            }
            // ry is always the parent
            parent[rx] = ry;
            if (rank[rx] == rank[ry])
                rank[ry]++;
            return true;
        }
    }

    public boolean equationsPossible(String[] equations) {
        final UnionFind uf = new UnionFind(26);
        Arrays.sort(equations, (s1, s2) -> {
            // true means "no exclamation mark" -> goes to beginning
            boolean p1 = !s1.contains("!");
            boolean p2 = !s2.contains("!");
            return Boolean.compare(p2, p1);
        });
        for (String s : equations) {
            int fv = s.charAt(0) - 'a';
            int sv = s.charAt(3) - 'a';
            boolean isEquality = !s.contains("!");
            if (isEquality) {
                uf.union(fv, sv);
            } else {
                if (uf.hasSameParent(fv, sv))
                    return false;
            }
        }

        return true;

    }
}