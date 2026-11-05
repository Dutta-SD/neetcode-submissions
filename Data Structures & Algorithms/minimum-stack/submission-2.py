class MinStack:
    def __init__(self):
        self.stk: list[tuple[int, int]] = []

    def push(self, val: int) -> None:
        if len(self.stk) == 0:
            return self.stk.append((val, val))

        _, prev_min = self.stk[-1]
        self.stk.append((val, min(prev_min, val)))

    def pop(self) -> None:
        return self.stk.pop()[0]

    def top(self) -> int:
        return self.stk[-1][0]

    def getMin(self) -> int:
        return self.stk[-1][1]
