class Solution(object):
    def complexNumberMultiply(self, num1, num2):
        x = [int(i) for i in num1[:-1].split('+')]
        y = [int(i) for i in num2[:-1].split('+')]
        return str(x[0] * y[0] - x[1] * y[1]) + '+' + str(x[0] * y[1] + x[1] * y[0]) + 'i'
