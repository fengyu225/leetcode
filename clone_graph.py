
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution:
    def cloneGraph_helper(self,node,m):
        if node in m:
            return m[node]
        n = UndirectedGraphNode(node.label)
        m[node] = n
        for c in node.neighbors:
            n.neighbors.append(self.cloneGraph_helper(c,m))
        return n

    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if node is None:
            return None
        m = {}
        return self.cloneGraph_helper(node,m)


if __name__ == "__main__":
    n0 = UndirectedGraphNode(0)
    n1 = UndirectedGraphNode(1)
    n2 = UndirectedGraphNode(2)
    n0.neighbors = [n1,n2]
    n1.neighbors = [n0,n2]
    n2.neighbors = [n0,n1]
    n = Solution().cloneGraph(n0)
    print n
