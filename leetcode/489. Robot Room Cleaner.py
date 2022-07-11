# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
# class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """

class Solution:
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """

        def goback():
            robot.turnLeft()
            robot.turnLeft()
            robot.move()
            robot.turnLeft()
            robot.turnLeft()

        def bracktrack(position, direction):
            row, col = position
            robot.clean()
            visited.add(position)
            for direction_offset in range(4):
                next_direction = (direction + direction_offset) % 4
                next_row, next_col = row + delta_steps[next_direction][0], col + delta_steps[next_direction][1]
                next_position = (next_row, next_col)
                if not next_position in visited and robot.move():
                    bracktrack(next_position, next_direction)
                    goback()
                robot.turnRight()

        visited = set()
        delta_steps = [[-1, 0], [0, 1], [1, 0], [0, -1]]  # can rotate in any direction
        bracktrack((0, 0), 0)

