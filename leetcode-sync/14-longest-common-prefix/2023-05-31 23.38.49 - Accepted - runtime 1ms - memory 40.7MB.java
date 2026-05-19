class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        int lastIdx = strs.length - 1;
        return longestCommonPrefix(strs[0], strs[lastIdx]);
    }

    private String longestCommonPrefix(String s1, String s2) {
        int idx = 0;
        int minLen = Math.min(s1.length(), s2.length());
        while (idx < minLen && s1.charAt(idx) == s2.charAt(idx)) idx++;
        return s1.substring(0, idx);
    }
}