class Solution:
    def intToRoman(self, num: int) -> str:
        integer_to_roman_map = {1: 'I',
                                4: 'IV',
                                5: 'V',
                                9: 'IX',
                                10: 'X',
                                40: 'XL',
                                50: 'L',
                                90: 'XC',
                                100: 'C',
                                400: 'CD',
                                500: 'D',
                                900: 'CM',
                                1000: 'M'}

        itr = [[i, r] for i, r in reversed(integer_to_roman_map.items())]

        def int_to_roman(n):
            if n == 0:
                return ''
            else:
                for i, rv in itr:
                    if n >= i:
                        q = n // i
                        rm = n % i
                        return rv * q + int_to_roman(rm)

        return int_to_roman(num)
