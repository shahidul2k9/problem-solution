from typing import List
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ln = []
        def generate(x):
            for i in range(0, 10, 1):
                if x != 0 or i != 0:
                    v = x * 10 + i
                    if v <= n:
                        ln.append(v)
                        generate(v)
        generate(0)
        return ln
