class Node(object):
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None

class Tree:
    def __init__(self,root=None):
        self.root = root
