/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

#include "header.h"

//bool search(unordered_map<int,vector<int> >& graph, vector<int>& color, int curr, int from){
//    for(int i:graph[curr]){
//        if(from>=0 && from == i) continue;
//        if(color[i] == 1) return false;
//        if(color[i] == 2) continue;
//        color[i] = 1;
//        bool res = search(graph, color, i, curr);
//        if(!res) return false;
//    }
//    color[curr] = 2;
//    return true;
//}
//
//bool validTree(int n, vector<pair<int, int> >& edges) {
//    //dfs
//    vector<int> color(n, 0);
//    if(edges.size() != n-1) return false;
//    unordered_map<int,vector<int> > m;
//    for(auto p:edges){
//        m[p.first].push_back(p.second);
//        m[p.second].push_back(p.first);
//    }
//    for(int i=0; i<n; i++){
//        if(color[i] != 0) continue;
//        color[i] = 1;
//        bool res = search(m, color, i, -1);
//        if(!res) return false;
//    }
//    return true;
//}

bool validTree(int n, vector<pair<int, int> >& edges) {

}

int main(){
    vector<pair<int,int> > edges = {
        {0, 1},
        {2, 3}
    };
    cout<<validTree(4, edges)<<endl;
    return 0;
}