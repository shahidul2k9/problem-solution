from typing import List


class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        encoded_text = []
        for text in strs:
            encoded_text.append('{:03d}'.format(len(text)))
            encoded_text.append(text)
        return ''.join(encoded_text)

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        decoded_text = []
        i = 0
        while i < len(s):
            text_len = int(s[i: i + 3])
            decoded_text.append(s[i + 3:i + 3 + text_len])
            i += 3 + text_len
        return decoded_text

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))