class Solution {
    private static String EMPTY_STRING = "";

    private Map<Character, Integer> getPopulatedMap(final String s) {
        final Map<Character, Integer> counts = new HashMap<>();
        for (char c : s.toCharArray()) {
            counts.merge(c, 1, Integer::sum);
        }
        return counts;
    }

    public final String minWindow(final String s, final String t) {
        if (t.length() == 0) {
            return EMPTY_STRING;
        }

        int l = 0, have = 0, minLen = Integer.MAX_VALUE, lMin = -1;

        final Map<Character, Integer> countT = getPopulatedMap(t);
        final Map<Character, Integer> window = getPopulatedMap(EMPTY_STRING);

        final int need = countT.size();

        for (int r = 0; r < s.length(); r++) {
            final char rChar = s.charAt(r);

            window.merge(rChar, 1, Integer::sum);

            if (countT.containsKey(rChar) && countT.get(rChar).equals(window.get(rChar))) {
                have++;
            }

            while (have == need) {
                final char lChar = s.charAt(l);

                // Update window result
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    lMin = l;
                }

                // Shrink possibilites
                l++;
                window.put(lChar, window.get(lChar) - 1);
                if (countT.containsKey(lChar) && window.get(lChar) < countT.get(lChar)) {
                    have--;
                }
            }
        }

        return minLen == Integer.MAX_VALUE ? EMPTY_STRING : s.substring(lMin, lMin + minLen);
    }
}