class PhoneDirectory:

    def __init__(self, maxNumbers: int):
        self.avl_start_index = 0
        self.max_slots = maxNumbers
        self.released_slots = set()

    def get(self) -> int:
        if len(self.released_slots) > 0:
            return self.released_slots.pop()
        elif self.avl_start_index < self.max_slots:
            avl_slot = self.avl_start_index
            self.avl_start_index += 1
            return avl_slot
        else:
            return -1

    def check(self, number: int) -> bool:
        return self.avl_start_index <= number < self.max_slots or number in self.released_slots

    def release(self, number: int) -> None:
        if not (self.avl_start_index <= number < self.max_slots):
            self.released_slots.add(number)

# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)