import random


class RandomizedSet:

    def __init__(self):
        self.index_map = dict()
        self.val_seq = []

    def insert(self, val: int) -> bool:
        index_map = self.index_map
        if val in index_map:
            return False
        else:
            index = len(self.val_seq)
            index_map[val] = index
            self.val_seq.append(val)
            return True

    def remove(self, val: int) -> bool:
        index_map = self.index_map
        if val not in index_map:
            return False
        else:
            val_seq = self.val_seq
            index = index_map[val]
            del index_map[val]
            if index !=  len(val_seq) - 1:
                last_val = val_seq[len(val_seq) - 1]
                val_seq[index] = last_val
                index_map[last_val] = index
            val_seq.pop()
            return True

    def getRandom(self) -> int:
        random_index = random.randrange(len(self.val_seq))
        return self.val_seq[random_index]
