class LRUCache {
    private static class Node<K, V> {
        K key;
        V value;
        Node<K, V> prev, next;

        Node(K k, V v) {
            key = k;
            value = v;
        }
    }

    private int c;
    private Map<Integer, Node<Integer, Integer>> cache;
    Node<Integer, Integer> head;
    Node<Integer, Integer> tail;

    public LRUCache(int capacity) {
        this.c = capacity;
        cache = new HashMap<>(capacity);
        head = new Node<>(null, null);
        tail = new Node<>(null, null);
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        Node<Integer, Integer> node = cache.get(key);
        if (node == null)
            return -1;
        removeNode(node);
        addNodeToHead(node);
        return node.value;
    }

    public void put(int key, int value) {
        Node<Integer, Integer> node = cache.get(key);
        if (node != null) {
            node.value = value;
            removeNode(node);
            addNodeToHead(node);
        } else {
            Node<Integer, Integer> newNode = new Node<>(key, value);

            if (cache.size() == c) {
                // Fill, evict
                cache.remove(tail.prev.key);
                removeNode(tail.prev);
            }
            addNodeToHead(newNode);
            cache.put(key, newNode);
        }

    }

    private void addNodeToHead(Node<Integer, Integer> node) {
        Node<Integer, Integer> oldHead = head.next;
        oldHead.prev = node;
        node.next = oldHead;

        head.next = node;
        node.prev = head;
    }

    private void removeNode(Node<Integer, Integer> node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        node.next = null;
        node.prev = null;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */