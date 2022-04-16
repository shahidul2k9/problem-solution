from typing import List


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        cf = []
        f = 1
        v = fruits[0]
        for i in range(1, len(fruits)):
            if fruits[i] == v:
                f += 1
            else:
                cf.append([v, f])
                f = 1
                v = fruits[i]
        cf.append([v, f])
        ans = sm = 0
        left = right = 0
        s = set()
        while right < len(cf):
            ans = max(ans, sm)
            v, f = cf[right]
            s.add(v)
            if len(s) > 2:
                left = right = left + 1
                sm = 0
                s.clear()
            else:
                sm += f
                right += 1
        return max(ans, sm)
