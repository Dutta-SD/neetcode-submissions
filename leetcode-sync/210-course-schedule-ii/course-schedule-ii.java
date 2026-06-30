class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>(numCourses);
        List<Integer> coursesOrder = new ArrayList<>();
        for (int i = 0; i < numCourses; i++)
            adj.add(new ArrayList<>());

        int[] inDegree = new int[numCourses];
        for (int[] pre : prerequisites) {
            adj.get(pre[1]).add(pre[0]); // prereq -> course
            inDegree[pre[0]]++; // count in same pass
        }

        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                queue.add(i);

        int completed = 0;
        while (!queue.isEmpty()) {
            int node = queue.remove();
            coursesOrder.add(node);
            completed++;
            for (int next : adj.get(node))
                if (--inDegree[next] == 0)
                    queue.add(next);
        }

        if (completed == numCourses) {
            return coursesOrder.stream().mapToInt(i -> i).toArray();
        } else {
            return new int[0];
        }
    }
}