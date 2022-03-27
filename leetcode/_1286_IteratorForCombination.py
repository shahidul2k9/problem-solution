class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.characters = characters
        self.combinationLength = combinationLength
        self.bitmask = (1 << len(characters)) - 1

    def next(self) -> str:
        seq = []
        if self.hasNext():
            for p in range(len(self.characters)):
                if (1 << (len(self.characters) - 1 - p)) & self.bitmask:
                    seq.append(self.characters[p])
            self.bitmask -= 1
        return ''.join(seq)

    def hasNext(self) -> bool:
        while self.bitmask > 0:
            if self.bitmask.bit_count() == self.combinationLength:
                return True
            else:
                self.bitmask -= 1
        return False

# ci = CombinationIterator("abcd", 2)
# print([ci.next() for _ in range(10)])
