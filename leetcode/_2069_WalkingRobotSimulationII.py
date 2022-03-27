class Robot:

    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height
        self.d = 0
        self.dxy = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        self.x = 0
        self.y = 0

    def step(self, num: int):
        num = num % (2 * self.width + 2 * self.height - 4)
        if num == 0 and self.x== 0 and self.y == 0:
            self.d = 3
        while num:
            dx, dy = self.dxy[self.d]
            if 0 <= self.x + dx < self.width and 0 <= self.y + dy < self.height:
                self.x = self.x + dx
                self.y = self.y + dy
                num = num - 1
            else:
                self.d = (self.d + 1) % 4

    def getPos(self):
        return [self.x, self.y]

    def getDir(self):
        match self.d:
            case 0:
                return 'East'
            case 1:
                return 'North'
            case 2:
                return 'West'
            case 3:
                return 'South'
