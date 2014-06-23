#include "header.h"

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    return node;
}

int main(){
    UndirectedGraphNode n0(0);
    UndirectedGraphNode n1(1);
    UndirectedGraphNode n2(2);
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
