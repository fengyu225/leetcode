/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

#include "header.h"

UndirectedGraphNode* clone(UndirectedGraphNode* root, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& s){
    if(!root) return NULL;
    if(s.find(root) != s.end()) return s[root];
    s[root] = new UndirectedGraphNode(root->label);
    for(int i=0; i<root->neighbors.size(); i++){
        UndirectedGraphNode* temp = clone(root->neighbors[i],s);
        s[root]->neighbors.push_back(temp);
        s[root->neighbors[i]]=temp;
    }
    return s[root];
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(!node) return NULL;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> s;
    UndirectedGraphNode* res = clone(node,s);
    return res;
}

int main(){
    UndirectedGraphNode n0(0);
    UndirectedGraphNode n1(0);
    UndirectedGraphNode n2(0);
    vector<UndirectedGraphNode*> n0_n;
    vector<UndirectedGraphNode*> n1_n;
    vector<UndirectedGraphNode*> n2_n;
    n0_n.push_back(&n1);
    n0_n.push_back(&n2);
    n1_n.push_back(&n2);
    n1_n.push_back(&n0);
    n2_n.push_back(&n0);
    n2_n.push_back(&n1);
    n2_n.push_back(&n2);
    UndirectedGraphNode* res = cloneGraph(&n0);
    return 0;
}
