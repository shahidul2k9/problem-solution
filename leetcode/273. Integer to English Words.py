class Solution:
    def numberToWords(self, num: int) -> str:
        digit_map = {
            1: 'One',
            2: 'Two',
            3: 'Three',
            4: 'Four',
            5: 'Five',
            6: 'Six',
            7: 'Seven',
            8: 'Eight',
            9: 'Nine',
            10: 'Ten',
            11: 'Eleven',
            12: 'Twelve',
            13: 'Thirteen',
            14: 'Fourteen',
            15: 'Fifteen',
            16: 'Sixteen',
            17: 'Seventeen',
            18: 'Eighteen',
            19: 'Nineteen',
            20: 'Twenty',
            30: 'Thirty',
            40: 'Forty',
            50: 'Fifty',
            60: 'Sixty',
            70: 'Seventy',
            80: 'Eighty',
            90: 'Ninety'}

        def single_digit(x) -> str:
            if x == 0:
                return ''
            else:
                return digit_map[x]

        def two_digit(x) -> str:
            if x < 10:
                return single_digit(x)
            elif x <= 20:
                return digit_map[x]
            else:
                text = digit_map[(x // 10) * 10] + ' ' + single_digit(x % 10)
                return text.strip()

        def three_digit(x) -> str:
            seq = []
            if x // 100 > 0:
                seq.append(single_digit(x // 100) + ' Hundred')
            x %= 100
            if x > 0:
                seq.append(two_digit(x))
            return ' '.join(seq)

        if num == 0:
            return 'Zero'
        else:
            seq = []
            billion = num // 1_000_000_000
            if billion > 0:
                seq.append(three_digit(billion) + ' Billion')
                num %= 1_000_000_000

            million = num // 1_000_000
            if million > 0:
                seq.append(three_digit(million) + ' Million')
                num %= 1_000_000

            thousand = num // 1000
            if thousand > 0:
                seq.append(three_digit(thousand) + ' Thousand')
                num %= 1000
            seq.append(three_digit(num))
            return ' '.join(seq).strip()

