from bisect import bisect_right


class SnapshotArray:

    def __init__(self, length: int):
        self.x = [[[0, 0]] for _ in range(length)]
        self.v = 0

    def set(self, index: int, val: int) -> None:
        el = self.x[index][-1]
        if el[0] != self.v :
            el = [self.v, val]
            self.x[index].append(el)
        else:
            el[1] = val

    def snap(self) -> int:
        self.v += 1
        return self.v - 1

    def get(self, index: int, snap_id: int) -> int:
        vl = self.x[index]
        bli = bisect_right(vl, snap_id, key=lambda x: x[0])
        return vl[bli - 1][1]
