class Codec:
    def __init__(self):
        self.host = "https://nai.com"
        self.url_map = {}

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        digits = []
        for i in range(10):
            r = random.randint(0, 61)
            if r < 10:
                digit_base = 48
            elif r < 36:
                digit_base = 65 - 10
            else:
                digit_base = 95 - 10 - 26
            digits.append(chr(digit_base + r))
        path = ''.join(digits)
        self.url_map[path] = longUrl
        return self.host + '/' + path

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        path = shortUrl.split('/')[-1]
        return self.url_map[path]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))

