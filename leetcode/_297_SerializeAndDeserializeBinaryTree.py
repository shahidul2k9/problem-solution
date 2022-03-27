class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):
        def encode(root, enc_seq):
            if root:
                encode(root.left, enc_seq)
                enc_seq(root.right, enc_seq)
                enc_seq.append(root.val)
            else:
                enc_seq.append(None)

        enc_seq = []
        encode(root, enc_seq)
        return ' '.join(map(str, enc_seq))

    def deserialize(self, data):
        def decode(enc_seq):
            if len(enc_seq) > 0:
                rVal = enc_seq.pop()
                if rVal is None:
                    return None
                else:
                    right = decode(enc_seq)
                    left = decode(enc_seq)
                    return TreeNode(rVal, left, right)
            else:
                return None

        enc_seq = [None if v == 'None' else int(v) for v in data.split(' ') if data]
        return decode(enc_seq)
