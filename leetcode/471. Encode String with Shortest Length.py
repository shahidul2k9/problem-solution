class Solution:
    def encode(self, s: str) -> str:
        dp = {}

        def shortest_encode(text) -> str:
            n = len(text)
            if n <= 4:
                return text

            if text not in dp:
                opt_encode = text
                for el in range(1, n // 2 + 1):
                    pattern = text[:el]
                    i = el
                    while True:
                        count = i // el
                        encoded_prefix = str(count) + '[' + shortest_encode(pattern) + ']'
                        if len(encoded_prefix) <= i:
                            ed = encoded_prefix + shortest_encode(text[i:])
                        else:
                            ed = text[:i] + shortest_encode(text[i:])
                        # print(text, el, i, pattern, ed, text[:i] + "|" + text[i:])
                        if len(opt_encode) > len(ed):
                            opt_encode = ed

                        if i + el <= n and text[i:i + el] == pattern:
                            i += el
                        else:
                            break

                dp[text] = opt_encode
            return dp[text]

        return shortest_encode(s)