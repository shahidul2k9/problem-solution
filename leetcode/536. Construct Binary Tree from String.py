# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def str2tree(self, s: str) -> Optional[TreeNode]:
        if len(s) == 0:
            return None
        else:
            text = '(' + s + ')'
            n = len(text)
            index = 0

            def readNode() -> TreeNode:
                nonlocal index
                if index >= n or text[index] != '(':
                    return None
                else:
                    index += 1  # ( opending parenthesis
                    if text[index] == '-':
                        sign = -1
                        index += 1
                    else:
                        sign = 1
                    val = 0
                    while text[index].isdigit():
                        val = val * 10 + ord(text[index]) - ord('0')
                        index += 1
                    node = TreeNode(val * sign, readNode(), readNode())
                    index += 1  # closing parenthesis
                    return node

            return readNode()

