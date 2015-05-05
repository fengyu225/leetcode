#include "header.h"

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* dfs(UndirectedGraphNode* root, unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>& map){
    UndirectedGraphNode* root_c = new UndirectedGraphNode(root->label);
    map[root] = root_c;
    for(int i=0;i<root->neighbors.size();i++){
        if(map.find(root->neighbors[i]) == map.end()){
            root_c->neighbors.push_back(dfs(root->neighbors[i],map));
        }
        else{
            root_c->neighbors.push_back(map[root->neighbors[i]]);
        }
    }
    return root_c;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(!node) return NULL;
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> map;
    return dfs(node,map);
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
