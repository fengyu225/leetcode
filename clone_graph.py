

class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        return node

if __name__ == "__main__":
    n0 = UndirectedGraphNode(0)
    n1 = UndirectedGraphNode(1)
    n2 = UndirectedGraphNode(2)
    n0.neighbors = [n1,n2]
    n1.neighbors = [n0,n2]
    n2.neighbors = [n0,n1]
    n = Solution().cloneGraph(n0)
    print n
