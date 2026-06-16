import java.util.Map;

class Solution {
    private static final String EMPTY_STRING = "";

    public final String minWindow(final String s, final String t) {
        // Edge cases handled immediately using native string properties
        if (t.isEmpty() || s.length() < t.length()) {
            return EMPTY_STRING;
        }

        // 128 covers all standard ASCII characters
        final int[] countT = new int[128];
        final int[] window = new int[128];

        // Populate required character frequencies efficiently
        int need = 0;
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (countT[c] == 0) {
                need++; // Count unique characters needed
            }
            countT[c]++;
        }

        int l = 0;
        int have = 0;
        int minLen = Integer.MAX_VALUE;
        int lMin = -1;

        // Sliding window over string 's'
        for (int r = 0; r < s.length(); r++) {
            final char rChar = s.charAt(r);
            window[rChar]++;

            // Safe primitive int comparison (no .equals() or caching bugs)
            if (countT[rChar] > 0 && window[rChar] == countT[rChar]) {
                have++;
            }

            // Shrink window from the left as much as possible
            while (have == need) {
                final int currentWindowLen = r - l + 1;
                if (currentWindowLen < minLen) {
                    minLen = currentWindowLen;
                    lMin = l;
                }

                final char lChar = s.charAt(l);
                window[lChar]--;

                // If window loses a required character frequency count, decrement 'have'
                if (countT[lChar] > 0 && window[lChar] < countT[lChar]) {
                    have--;
                }
                l++;
            }
        }

        return minLen == Integer.MAX_VALUE ? EMPTY_STRING : s.substring(lMin, lMin + minLen);
    }
}
