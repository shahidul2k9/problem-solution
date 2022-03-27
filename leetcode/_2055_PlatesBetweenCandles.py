from typing import List


class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        plates = [0] * (n + 1)
        for i in range(1, n + 1):
            plates[i] = plates[i - 1] + (1 if s[i - 1] == '*' else 0)
        right_candle = [0] * n
        left_candle = [0] * n
        for i in range(0, n):
            if s[i] == '|':
                left_candle[i] = i
            else:
                left_candle[i] = left_candle[i - 1] if i > 0 else float('inf')
        for i in range(n - 1, -1,-1):
            if s[i] == '|':
                right_candle[i] = i
            else:
                right_candle[i] = right_candle[i + 1] if i + 1 < n else float('-inf')
        answers = []
        for a, b in queries:
            x = right_candle[a]
            y = left_candle[b]
            if a <= x <= b and a <= y <= b and x <= y:
                answers.append(plates[y + 1] - plates[x])  # since x,y are 0 indexed
            else:
                answers.append(0)
        return answers
