from typing import List


class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        file_map = {}
        named_seq = []
        for name in names:

            if name not in file_map:
                file_map[name] = 1
                new_name = name
            else:
                version = file_map[name]
                while name + '(' + str(version) + ')' in file_map:
                    version += 1
                new_name = name + '(' + str(version) + ')'
                file_map[name] = version
                file_map[new_name] = 1
            named_seq.append(new_name)
        return named_seq


