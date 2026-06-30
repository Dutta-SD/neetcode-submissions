class Solution {
    private Map<Integer, List<Integer>> toAdjacencyList(int[][] p) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int idx = 0; idx < p.length; idx++) {
            int source = p[idx][1];
            int destination = p[idx][0];
            adj.computeIfAbsent(source, k -> new ArrayList<>()).add(destination);
        }

        return adj;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        final Map<Integer, List<Integer>> adj = toAdjacencyList(prerequisites);
        Queue<Integer> zeroNodes = new ArrayDeque<>();
        List<Integer> inDegrees = new ArrayList<>(numCourses);
        for (int i = 0; i < numCourses; i++) {
            inDegrees.add(0);
        }
        int coursesCompleted = 0;

        for (int s = 0; s < numCourses; s++) {
            if (adj.containsKey(s)) {
                for (int d = 0; d < adj.get(s).size(); d++) {
                    int destinationNode = adj.get(s).get(d);
                    int currentDegree = inDegrees.get(destinationNode);
                    inDegrees.set(destinationNode, currentDegree + 1);
                }
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (inDegrees.get(i) == 0) {
                zeroNodes.add(i);
            }
        }

        while (!zeroNodes.isEmpty()) {
            int node = zeroNodes.remove();
            coursesCompleted++;

            for (int d : adj.getOrDefault(node, Collections.emptyList())) {
                int updatedDegree = inDegrees.get(d) - 1;
                inDegrees.set(d, updatedDegree);

                if (updatedDegree == 0) {
                    zeroNodes.add(d);
                }
            }
        }

        return coursesCompleted == numCourses;
    }
}