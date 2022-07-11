# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:
from random import random
from typing import List


class Solution:
    def findSecretWord(self, wordlist: List[str], master: 'Master') -> None:
        for guess_count in range(10):
            rand_index = random.randint(0, len(wordlist) - 1)
            wordlist[rand_index], wordlist[len(wordlist) - 1] = wordlist[len(wordlist) - 1], wordlist[rand_index]
            guessed_word = wordlist[-1]
            match_count = master.guess(guessed_word)
            if match_count == 6:
                return guessed_word
            else:
                filtered_wordlist = []
                for i in range(len(wordlist) - 1):
                    match = 0
                    for pos in range(6):
                        if guessed_word[pos] == wordlist[i][pos]:
                            match += 1
                    if match == match_count:
                        filtered_wordlist.append(wordlist[i])
                wordlist = filtered_wordlist
