# """
# This is Sea's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Sea:
#    def hasShips(self, topRight: 'Point', bottomLeft: 'Point') -> bool:
#
#class Point:
#	def __init__(self, x: int, y: int):
#		self.x = x
#		self.y = y

class Solution:
    def countShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point') -> int:
        def count_on_x(left : int, right : int) -> int:
            if left > right:
                return 0
            elif sea.hasShips(Point(right, topRight.y), Point(left, bottomLeft.y)):
                if left == right:
                    return count_on_y(left, bottomLeft.y, topRight.y)
                else:
                    mid_x = (left + right)//2
                    return count_on_x(left, mid_x) + count_on_x(mid_x + 1, right)
            else:
                return 0
        def count_on_y(x : int, down : int, up : int)-> int:
            if down > up:
                return 0
            elif sea.hasShips(Point(x, up), Point(x, down)):
                if down == up:
                    return 1
                else:
                    mid_y = (down + up)//2
                    return count_on_y(x, down, mid_y) + count_on_y(x, mid_y + 1, up)
            else:
                return 0
        return count_on_x(bottomLeft.x, topRight.x)