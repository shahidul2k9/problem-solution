from typing import List


class Solution:
    def addBoldTag(self, s: str, words: List[str]) -> str:
        windows = []
        for pattern in words:
            pattern_len = len(pattern)
            for i in range(0, len(s) - pattern_len + 1):
                for k in range(pattern_len):
                    if s[i + k] != pattern[k]:
                        break
                else:
                    windows.append([i, i + pattern_len])

        windows.sort()
        stack = []
        for a, b in windows:
            if stack and stack[-1][1] >= a:
                stack[-1][1] = max(b, stack[-1][1])
            else:
                stack.append([a, b])
        styled_text = []
        i = 0
        for a, b in stack:
            if i < a:
                styled_text.append(s[i:a])
            styled_text.append('<b>' + s[a:b] + '</b>')
            i = b
        styled_text.append(s[i:])
        return ''.join(styled_text)
