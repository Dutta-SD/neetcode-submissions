class Solution {
    private static final char OB1 = '(';
    private static final char OB2 = '{';
    private static final char OB3 = '[';
    private static final char CB1 = ')';
    private static final char CB2 = '}';
    private static final char CB3 = ']';

    private char openingChar(final char currChar) {
        return switch (currChar) {
            case CB1 -> OB1;
            case CB2 -> OB2;
            case CB3 -> OB3;
            default -> currChar;
        };
    }

    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();

        for (char c : s.toCharArray()) {
            if (openingChar(c) == c) {
                stk.push(c);
            } else {
                if (!stk.empty() && stk.peek() == openingChar(c)) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
}