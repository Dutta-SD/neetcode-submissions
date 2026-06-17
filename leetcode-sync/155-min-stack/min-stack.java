class MinStack {
    private record Pair<K, V>(K first, V second) {
    }

    private final Deque<Pair<Integer, Integer>> stk;

    public MinStack() {
        stk = new ArrayDeque<>();
    }

    public void push(Integer value) {
        if (stk.isEmpty()) {
            stk.push(new Pair<Integer, Integer>(value, value));
        } else {
            Integer minValue = Math.min(value, stk.peek().second);
            stk.push(new Pair<Integer, Integer>(value, minValue));
        }

    }

    public void pop() {
        stk.pop();
    }

    public Integer top() {
        return stk.peek().first;

    }

    public Integer getMin() {
        return stk.peek().second;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */