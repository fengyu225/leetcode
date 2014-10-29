#include "header.h"

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* clone(UndirectedGraphNode* root, unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>& m){
    if(!root){
        return NULL;
    }
    if(m.find(root) != m.end())
        return m[root];
    UndirectedGraphNode* new_root = new UndirectedGraphNode(root->label);
    m[root] = new_root;
    for(int i=0; i<(root->neighbors).size(); i++){
        new_root->neighbors.push_back(clone(root->neighbors[i],m));
    }
    return new_root;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m;
    if(!node) return NULL;
    return clone(node,m);
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
