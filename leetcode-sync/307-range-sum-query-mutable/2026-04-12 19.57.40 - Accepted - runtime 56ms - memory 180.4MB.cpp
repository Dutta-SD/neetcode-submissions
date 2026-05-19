class NumArray {
    int n;
    vector<int> tree;
    vector<int> arr;

    void add(int i, int val) {
        for (; i <= n; i += i & (-i))
            tree[i] += val;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i))
            sum += tree[i];
        return sum;
    }

public:
    NumArray(vector<int>& nums)
        : n(nums.size()), tree(nums.size() + 1, 0),
          arr(nums.begin(), nums.end()) {
        for (int i = 0; i < n; i++)
            add(i + 1, nums[i]);
    }

    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        add(index + 1, diff);
    }

    int sumRange(int left, int right) { return query(right + 1) - query(left); }
};