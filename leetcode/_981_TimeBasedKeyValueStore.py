import bisect
import collections


class TimeMap:

    def __init__(self):
        self.repertory = collections.defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        val_seq = self.repertory[key]
        val_seq.append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        val_seq = self.repertory[key]
        val_index = bisect.bisect(val_seq, timestamp, key=lambda x: x[1]) - 1
        if val_index >= 0:
            return val_seq[val_index][0]
        else:
            return ''
