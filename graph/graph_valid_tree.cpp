/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

#include "header.h"

int set_find(unordered_map<int,int>& m, int v){
    if(m[v] == -1) return v;
    return set_find(m, m[v]);
}

void set_union(unordered_map<int,int>& m, int l, int r){
    int l_p = set_find(m, l);
    int r_p = set_find(m, r);
    m[l_p] = r_p;
}

bool validTree(int n, vector<pair<int, int> >& edges) {
    if(edges.size() != n-1) return false;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++) m[i] = -1;
    for(auto edge:edges){
        int p_0 = set_find(m, edge.first);
        int p_1 = set_find(m, edge.second);
        if(p_0 == p_1) return false;
        set_union(m, p_0, p_1);
    }
    return true;
}

int main(){
    vector<pair<int,int> > edges = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4}
    };
    cout<<validTree(5, edges)<<endl;
    return 0;
}