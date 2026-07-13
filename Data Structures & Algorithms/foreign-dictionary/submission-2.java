class Solution {
    private boolean invalidSequence = false;

    private Set<Character> getAllCharsInDictionary(final String[] words) {
        final Set<Character> chars = new HashSet<>();
        for (String s : words) {
            for (char ch : s.toCharArray()) {
                chars.add(ch);
            }
        }
        return chars;
    }

    private Map<Character, List<Character>> buildAdj(
        final String[] words, final Set<Character> allChars) {
        final Map<Character, List<Character>> adj = new HashMap<>();

        for (char c : allChars) {
            adj.put(c, new ArrayList<>());
        }

        for (int i = 0; i < words.length - 1; i++) {
            String w1 = words[i];
            String w2 = words[i + 1];

            if (w1.startsWith(w2) && w1.length() > w2.length()) {
                invalidSequence = true;
                return adj;
            }

            int j = 0;

            while (j < Math.min(w1.length(), w2.length()) && w1.charAt(j) == w2.charAt(j)) j++;

            if (j == Math.min(w1.length(), w2.length()))
                continue;

            adj.get(w1.charAt(j)).add(w2.charAt(j));
        }

        return adj;
    }

    private String topoSort(Map<Character, List<Character>> adj, Set<Character> allChars) {
        if (invalidSequence)
            return "";

        // in-degree of every character
        Map<Character, Integer> inDegree = new HashMap<>();
        for (char c : allChars) inDegree.put(c, 0);
        for (char from : adj.keySet())
            for (char to : adj.get(from)) inDegree.merge(to, 1, Integer::sum);

        // seed with all in-degree-0 chars (order doesn't matter — any valid topo order is accepted)
        Queue<Character> ready = new ArrayDeque<>();
        for (char c : allChars)
            if (inDegree.get(c) == 0)
                ready.add(c);

        StringBuilder order = new StringBuilder();
        while (!ready.isEmpty()) {
            char c = ready.poll();
            order.append(c);
            for (char next : adj.get(c))
                if (inDegree.merge(next, -1, Integer::sum) == 0)
                    ready.add(next);
        }

        // cycle → some chars never hit in-degree 0 → never enqueued → shorter output
        return order.length() == allChars.size() ? order.toString() : "";
    }

    public String foreignDictionary(String[] words) {
        final Set<Character> allChars = getAllCharsInDictionary(words);
        final Map<Character, List<Character>> adj = buildAdj(words, allChars);
        return topoSort(adj, allChars);
    }
}
