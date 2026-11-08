class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        changes = {
            5: 0,
            10: 0,
            20: 0,
        }

        for b in bills:
            if b == 5:
                changes[5] += 1
            elif b == 10:
                if changes[5] == 0:
                    return False
                changes[10] += 1
                changes[5] -= 1

            else:
                if changes[10] == 0:
                    if changes[5] < 3:
                        return False
                    changes[20] += 1
                    changes[5] -= 3
                else:
                    if changes[5] < 1:
                        return False
                    changes[20] += 1
                    changes[5] -= 1
                    changes[10] -= 1

        return True
