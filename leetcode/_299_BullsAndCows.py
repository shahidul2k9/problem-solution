from collections import Counter


class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        character_frequency = Counter(secret)
        N = len(secret)
        bulls = cows = 0
        for i, c in enumerate(guess):
            if secret[i] == guess[i]:
                bulls += 1
                character_frequency[c] -= 1
        for i, c in enumerate(guess):
            if secret[i] != guess[i] and c in character_frequency and character_frequency[c] > 0:
                cows += 1
                character_frequency[c] -= 1
        return ''.join([str(bulls), 'A', str(cows), 'B'])
