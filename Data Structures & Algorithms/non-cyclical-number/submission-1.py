UNVISITED, VISITED, VALID, INVALID = 0, 1, 2, 3


class Solution:
    def _dig_sq_sum(self, n):
        s, x = str(n), 0
        for d in s:
            x += int(d) * int(d)
        return x

    def V(self, idx, status):
        if status[idx] == UNVISITED:
            status[idx] = VISITED
            status[idx] = self.V(self._dig_sq_sum(idx), status)
        if status[idx] == VISITED:
            status[idx] = INVALID
        return status[idx]

    def _precompute(self):
        max_len = 1001
        status = [UNVISITED] * max_len
        status[0] = VALID
        status[1] = VALID

        for idx in range(max_len):
            if status[idx] == UNVISITED:
                self.V(idx, status)

        return status

    def isHappy(self, n: int) -> bool:
        status = self._precompute()
        return status[n] == VALID
