import re


class Solution:
    def lengthLongestPath(self, input: str) -> int:
        token_list = re.split("([\n\t]+)", input)
        dir_stack = []
        deepest_file_len = 0
        for token in token_list:
            if token.find('\n') >= 0:
                tab_count = token.count('\t')
                dir_stack = dir_stack[:tab_count]
            else:
                dir_stack.append(token)
                if token.find('.') >= 0:
                    deepest_file_len = max(deepest_file_len, sum(map(len, dir_stack)) + len(dir_stack) - 1)
        return deepest_file_len
