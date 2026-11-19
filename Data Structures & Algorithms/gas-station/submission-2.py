class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        start = 0

        while start < n:
            idx = start
            tank = gas[idx]

            while cost[idx] <= tank:
                tank -= cost[idx]
                idx = (idx + 1) % n
                tank += gas[idx]

                if tank <= 0 and cost[idx]:
                    break

                if idx == start:
                    return start

            start = max(start, idx) + 1
        return -1
