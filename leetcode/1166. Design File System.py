class FileSystem:

    def __init__(self):
        self.pm = dict()

    def createPath(self, path: str, value: int) -> bool:
        if path == '' or path == '/' or path[0] != '/':
            return False
        else:
            parent_file = path[:path.rfind('/')]
            pm = self.pm
            if (parent_file != '' and parent_file not in pm) or path in pm:
                return False
            pm[path] = value
            return True

    def get(self, path: str) -> int:
        if path in self.pm:
            return self.pm[path]
        else:
            return -1

# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)