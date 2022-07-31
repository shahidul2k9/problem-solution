import math


class MRUQueue:

    def __init__(self, n: int):
        self.n = n
        self.chunk_size = math.ceil(math.sqrt(n + 2000))
        self.chunks = [0] * self.chunk_size
        self.length = self.chunk_size ** 2
        self.nums = [i + 1 for i in range(self.length)]
        self.insert_index = n
        for i in range(n):
            self.chunks[i // self.chunk_size] += 1

    def fetch(self, k: int) -> int:
        elements = 0
        for chunk_index, chunk_element_count in enumerate(self.chunks):
            if k <= elements + chunk_element_count:
                i = chunk_index * self.chunk_size
                while elements < k:
                    if self.nums[i] > 0:
                        elements += 1
                    i += 1
                else:
                    self.nums[self.insert_index] = self.nums[i - 1]
                    self.nums[i - 1] = -1
                    self.chunks[chunk_index] -= 1
                    self.chunks[self.insert_index // self.chunk_size] += 1
                    self.insert_index += 1
                    return self.nums[self.insert_index - 1]
            else:
                elements += chunk_element_count

# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)