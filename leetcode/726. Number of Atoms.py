import collections


class Solution:
    def countOfAtoms(self, formula: str) -> str:
        token_list = []
        index = 0
        n = len(formula)
        while index < n:
            head = formula[index]
            num_seq = []
            index += 1
            if index < n and head.isalpha() and formula[index].islower():
                head = head + formula[index]
                index += 1
            while index < n and formula[index].isdigit():
                num_seq.append(formula[index])
                index += 1
            token_list.append([head, 1 if len(num_seq) == 0 else int(''.join(num_seq))])

        stack = []
        token_index = len(token_list) - 1
        factor = 1
        frequency_map = collections.defaultdict(int)
        while token_index >= 0:
            token, frequency = token_list[token_index]
            if token == ')':
                factor *= frequency
                stack.append(frequency)
            elif token == '(':
                factor //= stack.pop()
            else:
                frequency_map[token] += frequency * factor
            token_index -= 1

        flattened_formula = []
        for token in sorted(frequency_map.keys()):
            flattened_formula.append(token)
            frequency = frequency_map[token]
            if frequency > 1:
                flattened_formula.append(str(frequency))
        return ''.join(flattened_formula)
