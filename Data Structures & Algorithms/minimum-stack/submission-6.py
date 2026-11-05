class MinStack:
    def __init__(self):
        self.stk: list[tuple[int, int]] = []

    def push(self, val: int) -> None:
        return (
            self.stk.append((val, val))
            if len(self.stk) == 0
            else self.stk.append((val, min(self.getMin(), val)))
        )

    def pop(self) -> None:
        return self.stk.pop()[0]

    def top(self) -> int:
        return self.stk[-1][0]

    def getMin(self) -> int:
        return self.stk[-1][1]
