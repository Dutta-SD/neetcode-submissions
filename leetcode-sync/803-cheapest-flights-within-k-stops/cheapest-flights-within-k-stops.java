class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] prices = new int[n];
        Arrays.fill(prices, Integer.MAX_VALUE);
        prices[src] = 0;
        int[] tmpPrices = new int[n];

        for (int i = 0; i <= k; i++) {
            System.arraycopy(prices, 0, tmpPrices, 0, n);
            for (int[] edge : flights) {
                int s = edge[0];
                int d = edge[1];
                int p = edge[2];

                if (prices[s] == Integer.MAX_VALUE)
                    continue;
                if (prices[s] + p < tmpPrices[d])
                    tmpPrices[d] = prices[s] + p;
            }
            System.arraycopy(tmpPrices, 0, prices, 0, n);
        }

        return prices[dst] == Integer.MAX_VALUE ? -1 : prices[dst];

    }
}