class Solution {
    public boolean isPalindrome(int x) {
        String repr = String.valueOf(x);
        StringBuffer reprReversed = new StringBuffer(repr).reverse();
        return repr.equals(reprReversed.toString());
    }
}