from typing import List


class Solution:
    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        start_word_set = {frozenset(w) for w in startWords}
        match_count = 0
        for tw in targetWords:
            for i in range(len(tw)):
                psw = tw[:i] + tw[i + 1:]
                if frozenset(psw) in start_word_set:
                    match_count += 1
                    break
        return match_count
