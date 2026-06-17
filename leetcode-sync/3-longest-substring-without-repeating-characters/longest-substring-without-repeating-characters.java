class Solution {
    public int lengthOfLongestSubstring(String s) {
        final boolean arr[] = new boolean[256];

        int l = 0;
        int r = 0;
        int numUnique = 0;
        int maxWindowLen = 0;

        while (r < s.length()) {
            if (!arr[s.charAt(r)]) {
                // Empty so no conflict
                arr[s.charAt(r)] = true;
                numUnique++;
                maxWindowLen = Math.max(maxWindowLen, numUnique);
                r++;
            } else {
                // Dispute
                while (arr[s.charAt(r)]) {
                    arr[s.charAt(l)] = false;
                    numUnique--;
                    l++;
                }
            }
        }

        return maxWindowLen;
    }
}