from functools import lru_cache
from typing import List


class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:

        def eval(a, b, op):
            match op:
                case '+':
                    return a + b
                case '-':
                    return a - b
                case '*':
                    return a * b

        @lru_cache(maxsize=None)
        def combine(f, t, exp: str):
            s = []
            if exp.count('+', f, t + 1) > 0 or exp.count('-', f, t + 1) > 0 or exp.count('*', f, t + 1) > 0:
                for i in range(f, t + 1, 1):
                    if exp[i] in ['+', '-', '*']:
                        x = combine(f, i - 1, exp)
                        y = combine(i + 1, t, exp)
                        for a in x:
                            for b in y:
                                s.append(eval(a, b, exp[i]))
            else:
                s.append(int(exp[f:t + 1]))
            #print(f,t,s)
            return s

        return list(combine(0, len(expression) - 1, expression))


print(Solution().diffWaysToCompute("2*3-4*5"))
