import collections


class Solution:
    def maxRepOpt1(self, text: str) -> int:
        ch = text[0]
        n = 1
        block = []
        for index in range(1, len(text)):
            if text[index] == ch:
                n += 1
            else:
                block.append([ch, n])
                n = 1
                ch = text[index]
        block.append([ch, n])
        count_map = collections.defaultdict(int)
        max_len = 0
        for pos, [ch, n] in enumerate(block):
            count_map[ch] += 1
            max_len = max(max_len, n)

        for pos, [ch, n] in enumerate(block):
            if count_map[ch] > 1:
                max_len = max(max_len, n + 1)

        for i in range(1, len(block) - 1):
            ch1, n1 = block[i - 1]
            ch2, n2 = block[i + 1]
            if ch1 == ch2 and block[i][1] == 1:
                if count_map[ch1] >= 3:
                    max_len = max(max_len, n1 + n2 + 1)
                else:
                    max_len = max(max_len, n1 + n2)
        return max_len

