class Solution {
    public String longestCommonPrefix(String[] strs) {
        String lcp = strs[0];
        for (String currStr : strs){
            lcp = longestCommonPrefix(currStr, lcp);
        }
        return lcp;
    }

    private String longestCommonPrefix(String s1, String s2) {
        int idx = 0;
        if (s1 == null || s2 == null) return "";
        while (idx < s1.length() && idx < s2.length() && s1.charAt(idx) == s2.charAt(idx)) idx++;
        return s1.substring(0, idx);
    }
}