/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

#include "header.h"

//void search(unordered_map<int,vector<int> >& m, unordered_map<int,bool>& visited, int curr, int& c){
//    if(visited[curr] || m.find(curr) == m.end() || m[curr].size() == 0) return;
//    c--;
//    visited[curr] = true;
//    for(int n:m[curr]) search(m, visited, n, c); 
//}
//
//bool validTree(int n, vector<pair<int, int> >& edges) {
//    //dfs
//    int sz = edges.size();
//    if(sz != n-1) return false;
//    if(sz == 0 && n == 1) return true;
//    unordered_map<int,vector<int> > m;
//    for(auto e:edges){
//        if(m.find(e.first) == m.end()) m[e.first] = vector<int>();
//        m[e.first].push_back(e.second);
//        if(m.find(e.second) == m.end()) m[e.second] = vector<int>();
//        m[e.second].push_back(e.first);
//    }
//    unordered_map<int,bool> visited;
//    for(int i=0; i<n; i++) visited[i]=false;
//    int c = n;
//    search(m, visited, 0, c);
//    return c == 0;
//}

int f(unordered_map<int,int>& m, int i){
    if(m[i] == -1) return i;
    return f(m, m[i]);
}

void u(unordered_map<int,int>& m, int i, int j){
    int i_p = f(m, i);
    int j_p = f(m, j);
    m[i_p] = j_p;
}

bool validTree(int n, vector<pair<int, int> >& edges) {
    //union find
    //reference: http://www.geeksforgeeks.org/union-find/
    int sz = edges.size();
    if(sz != n-1) return false;
    unordered_map<int,int> parents;
    for(int i=0; i<n; i++) parents[i] = -1; 
    for(auto e:edges){
        int a = f(parents, e.first);
        int b = f(parents, e.second);
        if(a == b) return false;
        u(parents, a, b);
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