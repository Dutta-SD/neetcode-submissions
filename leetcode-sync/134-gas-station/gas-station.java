class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int totalGas = Arrays.stream(gas).sum();
        int totalCost = Arrays.stream(cost).sum();
        boolean found = false;

        if (totalCost > totalGas) {
            return -1;
        }

        int start = 0;
        int currentGas = 0;

        for (int i = 0; i < gas.length; i++) {
            currentGas += gas[i] - cost[i];

            if (currentGas < 0) {
                currentGas = 0;
                start = i + 1;
            }
        }

        return start;
    }
}